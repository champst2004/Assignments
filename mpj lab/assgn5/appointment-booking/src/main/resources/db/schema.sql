CREATE DATABASE IF NOT EXISTS appointment_db;
USE appointment_db;

CREATE TABLE IF NOT EXISTS appointments (
    appointment_id VARCHAR(50) PRIMARY KEY,
    user_name VARCHAR(100) NOT NULL,
    user_email VARCHAR(100) NOT NULL,
    appointment_date DATE NOT NULL,
    appointment_time TIME NOT NULL
);
