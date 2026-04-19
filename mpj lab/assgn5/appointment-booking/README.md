# Appointment Booking Web Application

A Java web application that books appointments using **Servlets**, stores data using **JDBC**, and shows booking confirmation using **JSP**.

## Features
- Accepts appointment ID, user name, user email, date, and time.
- Processes request through `AppointmentServlet`.
- Saves booking details in MySQL via JDBC.
- Displays saved details on `confirmation.jsp`.

## Project Structure
- `src/main/java/com/appointment/model/Appointment.java` - model class.
- `src/main/java/com/appointment/dao/AppointmentDAO.java` - JDBC persistence.
- `src/main/java/com/appointment/servlet/AppointmentServlet.java` - request handling.
- `src/main/webapp/index.jsp` - booking form.
- `src/main/webapp/confirmation.jsp` - confirmation page.
- `src/main/resources/db/schema.sql` - DB schema.

## Database Setup
1. Start MySQL.
2. Run script: `src/main/resources/db/schema.sql`.
3. Update DB credentials in `AppointmentDAO.java` if required.

## Run with Maven + Tomcat
1. Build WAR:
   ```bash
   mvn clean package
   ```
2. Copy `target/appointment-booking.war` into Tomcat `webapps` folder.
3. Start Tomcat.
4. Open:
   `http://localhost:8080/appointment-booking/`
