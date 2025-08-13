from pymongo import MongoClient

def insert_records(collection):
    records = [
        {
            "Hotel Id": 1,
            "Hotel Name": "Grand Palace",
            "Type": "Luxury",
            "Ratings": 4.8,
            "Address": {
                "Area": "MG Road",
                "City": "Bangalore",
                "Pincode": "560001"
            },
            "Rooms": [
                {"Roomno": 101, "Type": "Deluxe", "Price": 5000},
                {"Roomno": 102, "Type": "Suite", "Price": 8000}
            ],
            "Cuisines": ["Indian", "Italian", "Chinese"],
            "Likes": 1200
        },
        {
            "Hotel Id": 2,
            "Hotel Name": "Sea View Resort",
            "Type": "Resort",
            "Ratings": 4.5,
            "Address": {
                "Area": "Beach Road",
                "City": "Goa",
                "Pincode": "403001"
            },
            "Rooms": [
                {"Roomno": 201, "Type": "Standard", "Price": 3000},
                {"Roomno": 202, "Type": "Deluxe", "Price": 4500}
            ],
            "Cuisines": ["Seafood", "Goan", "Continental"],
            "Likes": 980
        },
        {
            "Hotel Id": 3,
            "Hotel Name": "Mountain Heights",
            "Type": "Boutique",
            "Ratings": 4.6,
            "Address": {
                "Area": "Hilltop",
                "City": "Manali",
                "Pincode": "175131"
            },
            "Rooms": [
                {"Roomno": 301, "Type": "Standard", "Price": 2500},
                {"Roomno": 302, "Type": "Suite", "Price": 5500}
            ],
            "Cuisines": ["Himachali", "Indian", "Chinese"],
            "Likes": 860
        },
        {
            "Hotel Id": 4,
            "Hotel Name": "City Comfort Inn",
            "Type": "Business",
            "Ratings": 4.2,
            "Address": {
                "Area": "Connaught Place",
                "City": "Delhi",
                "Pincode": "110001"
            },
            "Rooms": [
                {"Roomno": 401, "Type": "Standard", "Price": 3500},
                {"Roomno": 402, "Type": "Deluxe", "Price": 5000}
            ],
            "Cuisines": ["North Indian", "Chinese", "Fast Food"],
            "Likes": 750
        },
        {
            "Hotel Id": 5,
            "Hotel Name": "Royal Heritage",
            "Type": "Heritage",
            "Ratings": 4.7,
            "Address": {
                "Area": "Pink City",
                "City": "Jaipur",
                "Pincode": "302001"
            },
            "Rooms": [
                {"Roomno": 501, "Type": "Luxury", "Price": 7000},
                {"Roomno": 502, "Type": "Suite", "Price": 12000}
            ],
            "Cuisines": ["Rajasthani", "Indian", "Continental"],
            "Likes": 1150
        },
        {
            "Hotel Id": 6,
            "Hotel Name": "Lakeside Retreat",
            "Type": "Resort",
            "Ratings": 4.4,
            "Address": {
                "Area": "Lake View",
                "City": "Udaipur",
                "Pincode": "313001"
            },
            "Rooms": [
                {"Roomno": 601, "Type": "Standard", "Price": 4000},
                {"Roomno": 602, "Type": "Deluxe", "Price": 6500}
            ],
            "Cuisines": ["Rajasthani", "Indian", "Chinese"],
            "Likes": 890
        },
        {
            "Hotel Id": 7,
            "Hotel Name": "Desert Oasis",
            "Type": "Resort",
            "Ratings": 4.3,
            "Address": {
                "Area": "Sand Dunes",
                "City": "Jaisalmer",
                "Pincode": "345001"
            },
            "Rooms": [
                {"Roomno": 701, "Type": "Tent", "Price": 3500},
                {"Roomno": 702, "Type": "Luxury Tent", "Price": 6000}
            ],
            "Cuisines": ["Rajasthani", "Indian", "Arabic"],
            "Likes": 720
        },
        {
            "Hotel Id": 8,
            "Hotel Name": "Hill View Residency",
            "Type": "Budget",
            "Ratings": 4.0,
            "Address": {
                "Area": "Mall Road",
                "City": "Shimla",
                "Pincode": "171001"
            },
            "Rooms": [
                {"Roomno": 801, "Type": "Standard", "Price": 2000},
                {"Roomno": 802, "Type": "Deluxe", "Price": 3500}
            ],
            "Cuisines": ["North Indian", "Chinese"],
            "Likes": 560
        },
        {
            "Hotel Id": 9,
            "Hotel Name": "The Urban Stay",
            "Type": "Business",
            "Ratings": 4.1,
            "Address": {
                "Area": "BKC",
                "City": "Mumbai",
                "Pincode": "400051"
            },
            "Rooms": [
                {"Roomno": 901, "Type": "Standard", "Price": 4500},
                {"Roomno": 902, "Type": "Suite", "Price": 9000}
            ],
            "Cuisines": ["Indian", "Italian", "Chinese"],
            "Likes": 640
        },
        {
            "Hotel Id": 10,
            "Hotel Name": "Coastal Breeze",
            "Type": "Resort",
            "Ratings": 4.6,
            "Address": {
                "Area": "Marina Beach",
                "City": "Chennai",
                "Pincode": "600001"
            },
            "Rooms": [
                {"Roomno": 1001, "Type": "Standard", "Price": 3800},
                {"Roomno": 1002, "Type": "Suite", "Price": 7500}
            ],
            "Cuisines": ["South Indian", "Seafood", "Chinese"],
            "Likes": 1020
        }
    ]
    collection.insert_many(records)
    print("Hotel records inserted successfully.")


def display_records(collection):
    print("\nRecords in collection:")
    for doc in collection.find():
        print(doc)

def update_record(collection):
    id = int(input("Enter ID to update: "))
    newName = input("Enter new Name: ")
    result = collection.update_one({"Hotel Id": id}, {"$set": {"Hotel Name": newName}})
    if result.modified_count:
        print("Record updated successfully.")
    else:
        print("Record not found / no change made.")

def delete_record(collection):
    id = int(input("Enter ID to delete: "))
    result = collection.delete_one({"Hotel Id": id})
    if result.deleted_count:
        print("Record deleted successfully.")
    else:
        print("Record not found.")

def main():
    try:
        dbName = "Restaurant"
        tableName = "Hotel"
        client = MongoClient("localhost", 27017)
        db = client[dbName]

        if tableName not in db.list_collection_names():
            db.create_collection(tableName)
        
        collection = db[tableName]
        print("Connected to MongoDB")

        while True:
            print("1. Insert Records")
            print("2. Display Records")
            print("3. Update Record")
            print("4. Delete Record")
            print("5. Exit")
            choice = int(input("Enter choice: "))

            if choice == 1:
                insert_records(collection)
            elif choice == 2:
                display_records(collection)
            elif choice == 3:
                update_record(collection)
            elif choice == 4:
                delete_record(collection)
            elif choice == 5:
                print("Thank You!")
                break
            else:
                print("Invalid choice")

    except Exception as e:
        print("Error: ", e)

if __name__ == "__main__":
    main()
