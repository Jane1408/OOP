#include "stdafx.h"
#include "../Car/Car.h"

struct car_is_turned_off
{
	CCar testCar;
};

BOOST_FIXTURE_TEST_SUITE(when_car_is_turned_off, car_is_turned_off);

	BOOST_AUTO_TEST_CASE(car_already_turned_off)
	{
		BOOST_CHECK(!testCar.IsTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(car_cannot_be_turned_off_again)
	{
		BOOST_CHECK(!testCar.TurnOff());
	}

	BOOST_AUTO_TEST_CASE(car_can_be_turn_on)
	{
		BOOST_CHECK(testCar.TurnOn());
	}

	BOOST_AUTO_TEST_CASE(car_speed_must_be_zero)
	{
		BOOST_CHECK_EQUAL(testCar.GetSpeed(), 0);
	}

	BOOST_AUTO_TEST_CASE(car_gear_must_be_neutral)
	{
		BOOST_CHECK(testCar.GetGear() == Gearbox::NEUTRAL);
	}

	BOOST_AUTO_TEST_CASE(car_movement_direction_must_be_standing)
	{
		BOOST_CHECK(testCar.GetMovementDirection() == MovementDirection::STANDING);
	}

	BOOST_AUTO_TEST_CASE(car_gearbox_cannot_be_transferred)
	{
		BOOST_CHECK(!testCar.SetGear(Gearbox::FIRST));
	}

	BOOST_AUTO_TEST_CASE(car_speed_cannot_be_transferred)
	{
		BOOST_CHECK(!testCar.SetSpeed(20));
	}

	struct car_is_turned_on : car_is_turned_off
	{
		car_is_turned_on()
		{
			testCar.TurnOn();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(when_car_is_turned_on, car_is_turned_on);
		BOOST_AUTO_TEST_CASE(car_cannot_be_turned_on_again)
		{
			BOOST_CHECK(!testCar.TurnOn());
		}

		BOOST_AUTO_TEST_CASE(car_can_be_turn_off)
		{
			BOOST_CHECK(testCar.TurnOff());
		}

		BOOST_AUTO_TEST_CASE(car_gearbox_can_be_transferred_if_speed_in_range_this_gear)
		{
			BOOST_CHECK(testCar.SetGear(Gearbox::FIRST));
		}

		BOOST_AUTO_TEST_CASE(car_gearbox_cannot_be_transferred_if_speed_out_of_range_this_gear)
		{
			BOOST_CHECK(!testCar.SetGear(Gearbox::SECOND));
		}

		BOOST_AUTO_TEST_CASE(car_speed_cannot_be_transferred_by_the_great_value_if_gear_is_neutral)
		{
			BOOST_CHECK(!testCar.SetSpeed(20));
		}

		struct car_in_first_gear : car_is_turned_on
		{
			car_in_first_gear()
			{
				testCar.SetGear(Gearbox::FIRST);
			}
		};

		BOOST_FIXTURE_TEST_SUITE(when_car_is_on_first_gear, car_in_first_gear);
			BOOST_AUTO_TEST_CASE(car_cannot_be_turned_off_if_gear_is_not_neutral)
			{
				BOOST_CHECK(!testCar.TurnOff());
			}

			BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_if_speed_in_range_this_gear)
			{
				BOOST_CHECK(testCar.SetSpeed(20));
			}

			BOOST_AUTO_TEST_CASE(car_speed_cannot_be_transferred_if_speed_out_of_range_this_gear)
			{
				BOOST_CHECK(!testCar.SetSpeed(40));
			}

			BOOST_AUTO_TEST_CASE(car_movement_direction_must_be_standing)
			{
				BOOST_CHECK(testCar.GetMovementDirection() == MovementDirection::STANDING);
			}

			BOOST_AUTO_TEST_CASE(car_gear_can_be_transferred_to_back_gear)
			{
				BOOST_CHECK(testCar.SetGear(Gearbox::BACK));
			}

			BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_smallest_value_in_range_of_first_gear)
			{
				BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.second));
			}

			BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_greatest_value_in_range_of_first_gear)
			{
				BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.first));
			}

			struct car_in_first_gear_and_speed_is_20 : car_in_first_gear
			{
				car_in_first_gear_and_speed_is_20()
				{
					testCar.SetSpeed(20);
				}
			};

			BOOST_FIXTURE_TEST_SUITE(when_car_is_on_first_gear_and_speed_is_20, car_in_first_gear_and_speed_is_20);
				BOOST_AUTO_TEST_CASE(car_cannot_be_turned_off_if_speed_is_not_zero)
				{
					BOOST_CHECK(!testCar.TurnOff());
				}

				BOOST_AUTO_TEST_CASE(car_movement_direction_must_be_forward)
				{
					BOOST_CHECK(testCar.GetMovementDirection() == MovementDirection::FORWARD);
				}

				BOOST_AUTO_TEST_CASE(car_movement_direction_cannot_be_to_backward)
				{
					BOOST_CHECK(testCar.GetMovementDirection() != MovementDirection::BACKWARD);
				}

				BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_max_value_speed_of_this_gear_range)
				{
					BOOST_CHECK(testCar.SetSpeed(30));
				}

				BOOST_AUTO_TEST_CASE(car_gear_can_be_transferred_to_second_gear_if_speed_is_minimum_rate_at_second_gear_speed_range)
				{
					BOOST_CHECK(testCar.SetGear(Gearbox::SECOND));
				}

				struct car_in_second_gear_and_speed_is_40 : car_in_first_gear_and_speed_is_20
				{
					car_in_second_gear_and_speed_is_40()
					{
						testCar.SetGear(Gearbox::SECOND);
						testCar.SetSpeed(40);
					}
				};

				BOOST_FIXTURE_TEST_SUITE(when_car_in_second_gear_and_speed_is_40, car_in_second_gear_and_speed_is_40);

					BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_smallest_value_in_range_of_second_gear)
					{
						BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.second));
					}

					BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_greatest_value_in_range_of_second_gear)
					{
						BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.first));
					}

					struct car_in_third_gear_and_speed_is_50 : car_in_second_gear_and_speed_is_40
					{
						car_in_third_gear_and_speed_is_50()
						{
							testCar.SetGear(Gearbox::THIRD);
							testCar.SetSpeed(50);
						}
					};

					BOOST_FIXTURE_TEST_SUITE(when_car_in_third_gear_and_speed_is_50, car_in_third_gear_and_speed_is_50);

						BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_smallest_value_in_range_of_third_gear)
						{
							BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.second));
						}

						BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_greatest_value_in_range_of_third_gear)
						{
							BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.first));
						}

						struct car_in_fourth_gear_and_speed_is_60 : car_in_third_gear_and_speed_is_50
						{
							car_in_fourth_gear_and_speed_is_60()
							{
								testCar.SetGear(Gearbox::FOURTH);
								testCar.SetSpeed(60);
							}
						};

						BOOST_FIXTURE_TEST_SUITE(when_car_in_fourth_gear_and_speed_is_60, car_in_fourth_gear_and_speed_is_60);

							BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_smallest_value_in_range_of_fourth_gear)
							{
								BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.second));
							}

							BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_greatest_value_in_range_of_fourth_gear)
							{
								BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.first));
							}

							struct car_in_fifth_gear_and_speed_is_80 : car_in_fourth_gear_and_speed_is_60
							{
								car_in_fifth_gear_and_speed_is_80()
								{
									testCar.SetGear(Gearbox::FIFTH);
									testCar.SetSpeed(80);
								}
							};

							BOOST_FIXTURE_TEST_SUITE(when_car_in_fifth_gear_and_speed_is_80, car_in_fifth_gear_and_speed_is_80);

								BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_smallest_value_in_range_of_fifth_gear)
								{
									BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.second));
								}

								BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_greatest_value_in_range_of_fifth_gear)
								{
									BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.first));
								}


							BOOST_AUTO_TEST_SUITE_END();

						BOOST_AUTO_TEST_SUITE_END();

					BOOST_AUTO_TEST_SUITE_END();

				BOOST_AUTO_TEST_SUITE_END();

			BOOST_AUTO_TEST_SUITE_END();

		BOOST_AUTO_TEST_SUITE_END();

		struct car_in_back_gear : car_is_turned_on
		{
			car_in_back_gear()
			{
				testCar.SetGear(Gearbox::BACK);
			}
		};
		BOOST_FIXTURE_TEST_SUITE(when_car_is_on_back_gear, car_in_back_gear);
			BOOST_AUTO_TEST_CASE(car_movement_direction_must_be_to_standing)
			{
				BOOST_CHECK(testCar.GetMovementDirection() == MovementDirection::STANDING);
			}

			BOOST_AUTO_TEST_CASE(car_gear_can_be_transferred_to_first_gear)
			{
				BOOST_CHECK(testCar.SetGear(Gearbox::FIRST));
			}

			BOOST_AUTO_TEST_CASE(car_cannot_be_turn_off_if_gear_is_not_neutral_and_speed_is_zero)
			{
				BOOST_CHECK(!testCar.TurnOff());
			}

			BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_smallest_value_in_range_of_back_gear)
			{
				BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.second));
			}

			BOOST_AUTO_TEST_CASE(car_speed_can_be_transferred_to_greatest_value_in_range_of_back_gear)
			{
				BOOST_CHECK(testCar.SetSpeed(SPEED_RANGE.find(testCar.GetGear())->second.first));
			}

			struct car_in_back_gear_and_speed_is_10 : car_in_back_gear
			{
				car_in_back_gear_and_speed_is_10()
				{
					testCar.SetSpeed(10);
				}
			};

			BOOST_FIXTURE_TEST_SUITE(when_car_in_back_gear_and_speed_is_10, car_in_back_gear_and_speed_is_10);
				BOOST_AUTO_TEST_CASE(car_movement_direction_must_be_to_barward)
				{
					BOOST_CHECK(testCar.GetMovementDirection() == MovementDirection::BACKWARD);
				}

				BOOST_AUTO_TEST_CASE(car_gear_cannot_be_transferred_to_first_gear)
				{
					BOOST_CHECK(!testCar.SetGear(Gearbox::BACK));
				}

				BOOST_AUTO_TEST_CASE(car_speed_cannot_be_transferred_to_out_of_range_back_gear)
				{
					BOOST_CHECK(!testCar.SetSpeed(30));
				}

				struct car_in_neutral_gear_and_movement_direction_is_backward : car_in_back_gear_and_speed_is_10
				{
					car_in_neutral_gear_and_movement_direction_is_backward()
					{
						testCar.SetGear(Gearbox::NEUTRAL);
					}
				};

				BOOST_FIXTURE_TEST_SUITE(when_car_in_neutral_gear_and_movement_direction_is_backward, car_in_neutral_gear_and_movement_direction_is_backward);
					BOOST_AUTO_TEST_CASE(car_gear_cannot_be_transferred_to_first_gear_until_car_movement_direction_is_not_staynig)
					{
						BOOST_CHECK(!testCar.SetGear(Gearbox::FIRST));
					}

					BOOST_AUTO_TEST_CASE(car_cannot_be_turn_off_if_movement_direction_is_not_standing_and_speed_is_not_zero)
					{
						BOOST_CHECK(!testCar.TurnOff());
					}


				BOOST_AUTO_TEST_SUITE_END();

			BOOST_AUTO_TEST_SUITE_END();

		BOOST_AUTO_TEST_SUITE_END();

	BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE_END();