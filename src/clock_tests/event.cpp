#include "catch.hpp"
#include "../Clock/Event.cpp"

TEST_CASE("Callbacks") {

	SECTION("Should be equal when it's the same event with the same id") {
		Event e1;

		Event::Callback e1c1 = e1.Attach([](Event*) {});

		REQUIRE(e1c1.GetID() == e1c1.GetID());
	}


	SECTION("Should be unequal when it's the same event with two different ids") {

		Event e1;

		Event::Callback e1c1 = e1.Attach([](Event*) {});
		Event::Callback e1c2 = e1.Attach([](Event*) {});

		REQUIRE(e1c1.GetID() != e1c2.GetID());
	}

	SECTION("Should be equal when it's the same event with the same callback") {

		Event e1;

		Event::Callback e1c1 = e1.Attach([](Event*) {});

		REQUIRE(e1c1 == e1c1);
	}

	SECTION("Should be unequal when it's the same event with two different callbacks") {

		Event e1;

		Event::Callback e1c1 = e1.Attach([](Event*) {});
		Event::Callback e1c2 = e1.Attach([](Event*) {});

		REQUIRE(e1c1 != e1c2);
	}

	SECTION("Should be unequal when events are different") {

		Event e1;

		Event::Callback e1c1 = e1.Attach([](Event*) {});

		Event e2;
		Event::Callback e2c1 = e2.Attach([](Event*) {});

		REQUIRE(e1c1.GetID() != e2c1.GetID());
	}
}