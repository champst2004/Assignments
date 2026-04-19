<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="com.appointment.model.Appointment" %>
<!DOCTYPE html>
<html>
<head>
    <title>Booking Confirmation</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 40px; }
        .card { border: 1px solid #ccc; padding: 18px; width: 480px; border-radius: 8px; }
        .ok { color: #0a7a0a; }
    </style>
</head>
<body>
<%
    Appointment appointment = (Appointment) request.getAttribute("appointment");
    Boolean saved = (Boolean) request.getAttribute("saved");
%>

<div class="card">
    <h2>Appointment Confirmation</h2>
    <% if (saved != null && saved) { %>
        <p class="ok">Your appointment was booked successfully.</p>
    <% } else { %>
        <p>Appointment could not be saved.</p>
    <% } %>

    <p><strong>Appointment ID:</strong> <%= appointment.getAppointmentId() %></p>
    <p><strong>User Name:</strong> <%= appointment.getUserName() %></p>
    <p><strong>User Email:</strong> <%= appointment.getUserEmail() %></p>
    <p><strong>Date:</strong> <%= appointment.getAppointmentDate() %></p>
    <p><strong>Time:</strong> <%= appointment.getAppointmentTime() %></p>

    <p><a href="index.jsp">Book another appointment</a></p>
</div>
</body>
</html>
