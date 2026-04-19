<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <title>Appointment Booking</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 40px; }
        .container { width: 420px; }
        label { display: block; margin-top: 12px; }
        input { width: 100%; padding: 8px; margin-top: 4px; }
        button { margin-top: 16px; padding: 10px 14px; }
        .error { color: #b00020; margin-top: 12px; }
    </style>
</head>
<body>
<div class="container">
    <h2>Book an Appointment</h2>

    <% if (request.getAttribute("error") != null) { %>
        <div class="error"><%= request.getAttribute("error") %></div>
    <% } %>

    <form action="bookAppointment" method="post">
        <label for="appointmentId">Appointment ID</label>
        <input type="text" id="appointmentId" name="appointmentId" required>

        <label for="userName">User Name</label>
        <input type="text" id="userName" name="userName" required>

        <label for="userEmail">User Email</label>
        <input type="email" id="userEmail" name="userEmail" required>

        <label for="appointmentDate">Date</label>
        <input type="date" id="appointmentDate" name="appointmentDate" required>

        <label for="appointmentTime">Time</label>
        <input type="time" id="appointmentTime" name="appointmentTime" required>

        <button type="submit">Book Appointment</button>
    </form>
</div>
</body>
</html>
