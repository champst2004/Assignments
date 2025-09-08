% --------------------------
% Automobile Expert System
% --------------------------

% Car facts
% cartype(Car, Transmission).
cartype(honda_civic, manual).
cartype(bmw_x5, automatic).
cartype(tesla_model3, automatic).
cartype(suzuki_swift, manual).
cartype(audi_a8, automatic).

% model(Car, Type).
model(honda_civic, sedan).
model(bmw_x5, suv).
model(tesla_model3, luxury).
model(suzuki_swift, hatchback).
model(audi_a8, luxury).

% fueltype(Car, Fuel).
fueltype(honda_civic, petrol).
fueltype(bmw_x5, diesel).
fueltype(tesla_model3, electric).
fueltype(suzuki_swift, petrol).
fueltype(audi_a8, hybrid).

% price(Car, Range).
price(honda_civic, medium).
price(bmw_x5, high).
price(tesla_model3, luxury).
price(suzuki_swift, low).
price(audi_a8, luxury).

% --------------------------
% User preferences
% purpose(User, Need).
purpose(user1, family).
purpose(user2, sporty).
purpose(user3, eco).
purpose(user4, budget).
purpose(user5, luxury_travel).

% budget(User, Range).
budget(user1, medium).
budget(user2, high).
budget(user3, medium).
budget(user4, low).
budget(user5, luxury).

% --------------------------
% Rules for suggesting cars
% --------------------------

% Family users prefer SUVs or Sedans
suggest_car(User, Car) :- purpose(User, family), (model(Car, suv) ; model(Car, sedan)).

% Sporty users prefer sports or hatchbacks
suggest_car(User, Car) :- purpose(User, sporty), (model(Car, sports) ; model(Car, hatchback)).

% Eco users prefer electric or hybrid
suggest_car(User, Car) :- purpose(User, eco), (fueltype(Car, electric) ; fueltype(Car, hybrid)).

% Budget users prefer low-price cars
suggest_car(User, Car) :- purpose(User, budget), price(Car, low).

% Luxury travel users prefer luxury cars with automatic transmission
suggest_car(User, Car) :- purpose(User, luxury_travel), model(Car, luxury), cartype(Car, automatic).