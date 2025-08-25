from pymongo import MongoClient

def insert_records(collection):
    # records = [
    #     {
    #         "Hotel Id": 1,
    #         "Hotel Name": "Grand Palace",
    #         "Type": "Luxury",
    #         "Ratings": 4.8,
    #         "Address": {
    #             "Area": "MG Road",
    #             "City": "Bangalore",
    #             "Pincode": "560001"
    #         },
    #         "Rooms": [
    #             {"Roomno": 101, "Type": "Deluxe", "Price": 5000},
    #             {"Roomno": 102, "Type": "Suite", "Price": 8000}
    #         ],
    #         "Cuisines": ["Indian", "Italian", "Chinese"],
    #         "Likes": 1200
    #     }
    # ]

    records = []
    n = int(input("Enter number of hotels: "))
    for i in range(n):
        hotel = {}
        hotel["Hotel Id"] = int(input("Enter hotel id: "))
        hotel["Hotel Name"] = input("Enter hotel name: ")
        hotel["Type"] = input("Enter hotel type: ")
        hotel["Ratings"] = float(input("Enter hotel ratings: "))
        hotel["Address"] = {}
        hotel["Address"]["Area"] = input("Enter hotel area: ")
        hotel["Address"]["City"] = input("Enter hotel city: ")
        hotel["Address"]["Pincode"] = int(input("Enter hotel pincode: "))
        hotel["Rooms"] = []
        num_rooms = int(input("Enter number of rooms: "))
        for j in range(num_rooms):
            room = {}
            room["RoomNo"] = int(input("Enter room no.: "))
            room["Type"] = input("Enter room type: ")
            room["Price"] = int(input("Enter room price: "))
            hotel["Rooms"].append(room)
        hotel["Cuisines"] = input("Enter cuisines: ").split(",")
        hotel["Likes"] = int(input("Enter likes: "))
        records.append(hotel)

    collection.insert_many(records)
    print("Hotel records inserted successfully.")


def display_records(collection):
    print("\nRecords in collection:")
    for doc in collection.find():
        for hehe in doc:
            print(f"{hehe}: {doc[hehe]}")
        print()

def update_record(collection):
    id = int(input("Enter ID to update: "))
    newName = input("Enter new Name: ")
    result = collection.update_one({"Hotel Id": id}, {"$set": {"Hotel Name": newName}})
    if result.modified_count:
        print(result.modified_count)
        print("Record updated successfully.")
    else:
        print("Record not found / no change made.")

def delete_record(collection):
    id = int(input("Enter ID to delete: "))
    result = collection.delete_many({"Hotel Id": id})
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
        collection.delete_many({})
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
