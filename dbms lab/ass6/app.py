from flask import Flask, render_template, request, redirect, flash, session
from db import db, cursor
import random

app = Flask(__name__)
app.secret_key = "champst2004"

@app.route("/")
@app.route("/home")
def home():
    return render_template("home.html")

@app.route("/create", methods=["GET", "POST"])
def create():
    if request.method == "POST":
        name = request.form["name"]
        acc_no = random.randint(100000, 999999)
        branch_name = request.form.get("branch")
        balance = request.form["balance"]
        cursor.execute("insert into bank values(%s, %s, %s, %s)", (name, acc_no, branch_name, balance))
        db.commit()
        flash("Account Created successfully", "success")
        return redirect("/view")
    return render_template("create.html")

@app.route("/view")
def view():
    cursor.execute("select * from bank")
    bank = cursor.fetchall()
    return render_template("view.html", bank = bank)

@app.route("/admin", methods=["GET", "POST"])
def admin():
    if request.method == "POST":
        name = request.form["name"]
        pin = request.form["pin"]

        cursor.execute("SELECT * FROM admin WHERE name=%s AND pin=%s", (name, pin))
        admin_data = cursor.fetchone()

        if admin_data:
            session["admin"] = name
            flash("Login successful!", "success")
            return redirect("/admin_dashboard")
        else:
            flash("Invalid credentials!", "danger")

    return render_template("admin.html")

@app.route("/admin_dashboard")
def admin_dashboard():
    if "admin" not in session:
        flash("Please log in as admin first!", "warning")
        return redirect("/admin")

    cursor.execute("select * from bank")
    bank = cursor.fetchall()
    return render_template("admin_dashboard.html", bank = bank)

@app.route("/delete/<int:no>")
def delete(no):
    cursor.execute("DELETE FROM bank WHERE acc_no = %s", (no,))
    db.commit()
    flash("Account deleted successfully!", "success")
    return redirect("/admin_dashboard")

@app.route("/logout")
def logout():
    session.pop("admin", None)
    flash("Logged out successfully.", "info")
    return redirect("/admin")

if __name__ == "__main__":
    app.run(debug=True)