package com.appointment.dao;

import com.appointment.model.Appointment;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class AppointmentDAO {

    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/appointment_db";
    private static final String JDBC_USER = "root";
    private static final String JDBC_PASSWORD = "cst4";

    private static final String INSERT_SQL = "INSERT INTO appointments (appointment_id, user_name, user_email, appointment_date, appointment_time) VALUES (?, ?, ?, ?, ?)";

    public boolean saveAppointment(Appointment appointment) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException("MySQL JDBC Driver not found.", e);
        }

        try (Connection connection = DriverManager.getConnection(JDBC_URL, JDBC_USER, JDBC_PASSWORD);
             PreparedStatement statement = connection.prepareStatement(INSERT_SQL)) {

            statement.setString(1, appointment.getAppointmentId());
            statement.setString(2, appointment.getUserName());
            statement.setString(3, appointment.getUserEmail());
            statement.setString(4, appointment.getAppointmentDate());
            statement.setString(5, appointment.getAppointmentTime());

            return statement.executeUpdate() > 0;
        } catch (SQLException e) {
            throw new RuntimeException("Error while saving appointment.", e);
        }
    }
}
