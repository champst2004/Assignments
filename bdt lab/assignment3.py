from pymongo import MongoClient

def insert_records(collection):
    records = [
        {"rno": "1", "Name": "ST"},
        {"rno": "2", "Name": "TR"},
        {"rno": "3", "Name": "NB"},
        {"rno": "4", "Name": "SP"},
        {"rno": "5", "Name": "FA"},
        {"rno": "6", "Name": "AP"},
        {"rno": "7", "Name": "AK"},
        {"rno": "8", "Name": "MT"},
        {"rno": "9", "Name": "RR"},
        {"rno": "10", "Name": "NN"}
    ]
    collection.insert_many(records)
    print("Records inserted successfully.")

def display_records(collection):
    print("\nRecords in collection:")
    for doc in collection.find():
        print(doc)

def update_record(collection):
    oldName = input("Enter Name to update: ")
    newName = input("Enter new Name: ")
    result = collection.update_one({"Name": oldName}, {"$set": {"Name": newName}})
    if result.modified_count:
        print("Record updated successfully.")
    else:
        print("Record not found / no change made.")

def delete_record(collection):
    name = input("Enter Name to delete: ").strip()
    result = collection.delete_one({"Name": name})
    if result.deleted_count:
        print("Record deleted successfully.")
    else:
        print("Record not found.")

def main():
    try:
        dbName = input("Enter database name: ")
        tableName = input("Enter table name: ")
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
