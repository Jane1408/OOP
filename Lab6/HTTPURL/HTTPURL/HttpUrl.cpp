#include "stdafx.h"
#include "HttpUrl.h"

const std::map <std::string, Protocol> MapOfProtocol = { {"http", Protocol::HTTP},
	{"https", Protocol::HTTPS}
};

//const std::set<char> Digits = { '0',  '1', '2', '3', '4', '5', '6', '7', '8', '9' };

const std::set<char> WrongSymbols = { '\t', ' ', '/', '\\' };

CHttpUrl::CHttpUrl(std::string const& url)
{
	ParsingUrl(url);
}

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & document, Protocol protocol, unsigned short port)
	: m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
	, m_port(port)
{
	if (!IsDomainCorrect())
	{
		throw CUrlParsingError("Invalid domain");
	}
}

std::string CHttpUrl::GetURL() const
{
	std::string url = (m_protocol == HTTP ? "http://" : "https://");
	url += m_domain;
	if ((m_protocol == HTTP && m_port != 80) || (m_protocol == HTTPS && m_port != 443))
	{
		url += ":" + std::to_string(m_port);
	}
	url += m_document;
	return url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

void CHttpUrl::ParsingUrl(std::string const& url)
{
	ParsingProtocol(url);
	ParsingDomain(url);
	ParsingPort(url);
	ParsingDocument(url);

}

void CHttpUrl::ParsingProtocol(std::string const& url)
{
	auto pos = url.find("://");

	if (pos == std::string::npos)
	{
		throw CUrlParsingError("Protocol parsing error");
	}
	std::string protocol = url.substr(0, pos);
	if (MapOfProtocol.find(protocol) == MapOfProtocol.end())
	{
		throw CUrlParsingError("Protocol parsing error");
	}
	m_pos = pos + 3;
	m_protocol = MapOfProtocol.find(protocol)->second;
}

void CHttpUrl::ParsingDomain(std::string const& url)
{
	auto pos = url.find(':', m_pos);
	if (pos == std::string::npos)
	{
		pos = url.find('/', m_pos);
		pos = (pos == std::string::npos ? url.size() : pos);
	}
	auto domain = url.substr(m_pos, pos - m_pos);
	m_pos = pos;
	if (!IsDomainCorrect())
	{
		throw CUrlParsingError("Invalid domain");
	}
	m_domain = domain;
	
}

void CHttpUrl::ParsingPort(std::string const& url)
{
	if (url[m_pos] == ':')
	{
		auto pos = url.find('/', m_pos);
		std::string port;
		++m_pos;
		if (pos == std::string::npos)
		{
			port = url.substr(m_pos, url.size() - m_pos + 1);
		}
		else
		{
			port = url.substr(m_pos, pos - m_pos );
		}
		m_pos = pos;

		//auto notDigit = [](char const& ch) { return  isdigit(ch); };
		if (port.size() > 3 || !(std::any_of(port.begin(), port.end(), isdigit)))
		{
			throw CUrlParsingError("Port parsing error");
		}
		if (port.size() == 0)
		{
			SetDefoultPort();
		}
		m_port = static_cast<unsigned short>(std::atoi(port.c_str()));
	}
	else if (url[m_pos] == '/')
	{
		SetDefoultPort();
	}
	else
	{
		throw CUrlParsingError("Port parsing error");
	}
}

void CHttpUrl::ParsingDocument(std::string const& url)
{
	std::string doc;
	if (m_pos >= url.size())
	{
		m_document = "/";
	}
	else
	{
		if (url[m_pos] != '/')
		{
			doc += '/';
		}
		doc += url.substr(m_pos, url.size() - m_pos);;
		m_document = doc;
	}
}

void CHttpUrl::SetDefoultPort()
{
	switch (m_protocol)
	{
	case HTTP: m_port = 80; break;
	case HTTPS: m_port = 443; break;
	}
}

bool CHttpUrl::IsDomainCorrect()
{
	auto check = [](char const& arg) { return WrongSymbols.find(arg) != WrongSymbols.end(); };
	if (std::any_of(m_domain.begin(), m_domain.end(), check))
	{
		return false;
	}
	return true;
}