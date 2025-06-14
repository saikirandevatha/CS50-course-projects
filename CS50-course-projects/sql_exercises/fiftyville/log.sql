-- Keep a log of any SQL queries you execute as you solve the mystery.

-- check the no of crimes on Humphrey Street on July 28th 2021; the following is the crime screne report for cs50 duck burglary
-- 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
select * from crime_scene_reports where street like '%humphrey%' AND year='2021' AND month = '7' AND day='28';


-- look up transcripts with bakery keyowrd; the following are the transcipts
-- | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
-- | 192 | Kiana   | 2021 | 5     | 17  | I saw Richard take a bite out of his pastry at the bakery before his pastry was stolen from him.
select * from interviews where transcript like '%bakery%';


-- atm transactions on july 28 2021; here are the results
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35

select * from atm_transactions where year='2021' and month = '7' and day ='28' and atm_location like '%leggett%' and transaction_ty
pe ='withdraw';



--get the airport id for fiftyville
-- | id | abbreviation |          full_name          |    city    |
-- +----+--------------+-----------------------------+------------+
-- | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
select * from airports where city='Fiftyville';


-- check the flights out of fiftyville on july 28 2021; here are the results
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20
select * from flights where origin_airport_id = 8 and year='2021' and month ='7' and day='29';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery;
-- | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
select *  from bakery_security_logs where activity='exit' and year=2021 and month=7 and day=28 and hour =10 and minute BETWEEN 15 AND 25;


---- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- | 234 | (609) 555-5876 | (389) 555-5198 | 2021 | 7     | 28  | 60       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
select * from phone_calls where year=2021 and month=7 and day=28 and duration <=60;

select * from people where passport_number in (
        select passport_number from passengers where flight_id in (
            select id from flights where origin_airport_id = 8 and year='2021' and month ='7' and day='28'))
         AND license_plate in (
            select license_plate  from bakery_security_logs where activity='exit' and year=2021 and month=7 and day=28 and hour >=10);


 select * from people where license_plate='13FNH73';
-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 745650 | Sophia | (027) 555-1068 | 3642612721      | 13FNH73

select * from bakery_security_logs where license_plate ='13FNH73';
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 169 | 2021 | 7     | 27  | 11   | 11     | entrance | 13FNH73       |
-- | 187 | 2021 | 7     | 27  | 13   | 25     | exit     | 13FNH73       |
-- | 259 | 2021 | 7     | 28  | 10   | 14     | entrance | 13FNH73       |
-- | 288 | 2021 | 7     | 28  | 17   | 15     | exit     | 13FNH73       |
-- | 320 | 2021 | 7     | 29  | 12   | 49     | entrance | 13FNH73       |
-- | 335 | 2021 | 7     | 29  | 16   | 20     | exit     | 13FNH73       |
-- | 357 | 2021 | 7     | 30  | 9    | 12     | entrance | 13FNH73       |
-- | 420 | 2021 | 7     | 30  | 16   | 5      | exit     | 13FNH73

select * from people  where phone_number in (select caller from phone_calls where year=2021 and month=7 and day=28) and  license_plate  in (select license_plate  from bakery_security_logs where activity='exit' and year=2021 and month=7 and day=28 and hour =10 ) and passport_number in (select passport_number from passengers where flight_id in (18,23,36,43,53));

select * from people  where phone_number in (select caller from phone_calls where year=2021 and month=7 and day=28 and duration <=60) and  license_plate  in (select license_plate  from bakery_security_logs where activity='exit' and year=2021 and month=7 and day=28 and hour =10 and minute BETWEEN 15 AND 25);;

select count(passport_number) from passengers where flight_id in (
        select id from flights where origin_airport_id = 8 and year='2021' and month ='7' and day='28');

select id from flights where origin_airport_id = 8 and year='2021' and month ='7' and day='29';
select count(passport_number) from passengers where flight_id in (1,6,17,34,35);


select * from people where passport_number in (
    select passport_number from passengers where flight_id in (
        select id from flights where origin_airport_id = 8 and year='2021' and month ='7' and day='29' and hour = '8'))
        AND license_plate in (
            select license_plate  from bakery_security_logs where activity='exit' and year=2021 and month=7 and day=28 and hour >=10 and minute BETWEEN 15 and 25)
        AND phone_number IN (
            select caller from phone_calls where year=2021 and month=7 and day=28 and duration <=60)
        AND id IN (
                select person_id from bank_accounts where account_number in (
                    select account_number from atm_transactions where year='2021' and month = '7' and day ='28' and atm_location like '%leggett%' and transaction_type ='withdraw')
                    );

--                     +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |

select * from people where passport_number in (
        select passport_number from passengers where flight_id in (
            select id from flights where origin_airport_id = 8 and year='2021' and month ='7' and day='29'))
         AND license_plate in (
            select license_plate  from bakery_security_logs where activity='exit' and year=2021 and month=7 and day=28 and hour >=10);




CREATE TABLE crime_scene_reports (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    street TEXT,
    description TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE interviews (
    id INTEGER,
    name TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    transcript TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE atm_transactions (
    id INTEGER,
    account_number INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    atm_location TEXT,
    transaction_type TEXT,
    amount INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE bank_accounts (
    account_number INTEGER,
    person_id INTEGER,
    creation_year INTEGER,
    FOREIGN KEY(person_id) REFERENCES people(id)
);
CREATE TABLE airports (
    id INTEGER,
    abbreviation TEXT,
    full_name TEXT,
    city TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE flights (
    id INTEGER,
    origin_airport_id INTEGER,
    destination_airport_id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
);
CREATE TABLE passengers (
    flight_id INTEGER,
    passport_number INTEGER,
    seat TEXT,
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);
CREATE TABLE phone_calls (
    id INTEGER,
    caller TEXT,
    receiver TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    duration INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE people (
    id INTEGER,
    name TEXT,
    phone_number TEXT,
    passport_number INTEGER,
    license_plate TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE bakery_security_logs (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    activity TEXT,
    license_plate TEXT,
    PRIMARY KEY(id)
);

