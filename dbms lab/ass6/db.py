import mysql.connector
db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="cst4",
    database="assgn6"
)

cursor = db.cursor(dictionary=True)