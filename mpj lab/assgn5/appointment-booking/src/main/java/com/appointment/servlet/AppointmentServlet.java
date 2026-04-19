package com.appointment.servlet;

import com.appointment.dao.AppointmentDAO;
import com.appointment.model.Appointment;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/bookAppointment")
public class AppointmentServlet extends HttpServlet {

    private final AppointmentDAO appointmentDAO = new AppointmentDAO();

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        Appointment appointment = new Appointment();
        appointment.setAppointmentId(request.getParameter("appointmentId"));
        appointment.setUserName(request.getParameter("userName"));
        appointment.setUserEmail(request.getParameter("userEmail"));
        appointment.setAppointmentDate(request.getParameter("appointmentDate"));
        appointment.setAppointmentTime(request.getParameter("appointmentTime"));

        if (isInvalid(appointment)) {
            request.setAttribute("error", "All fields are required.");
            RequestDispatcher dispatcher = request.getRequestDispatcher("index.jsp");
            dispatcher.forward(request, response);
            return;
        }

        boolean saved = appointmentDAO.saveAppointment(appointment);
        request.setAttribute("appointment", appointment);
        request.setAttribute("saved", saved);

        RequestDispatcher dispatcher = request.getRequestDispatcher("confirmation.jsp");
        dispatcher.forward(request, response);
    }

    private boolean isInvalid(Appointment appointment) {
        return isBlank(appointment.getAppointmentId())
                || isBlank(appointment.getUserName())
                || isBlank(appointment.getUserEmail())
                || isBlank(appointment.getAppointmentDate())
                || isBlank(appointment.getAppointmentTime());
    }

    private boolean isBlank(String value) {
        return value == null || value.trim().isEmpty();
    }
}
