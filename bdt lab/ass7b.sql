create 'library', 'books', 'authors', 'members'

put 'library', 'book_1', 'books:title', 'To Kill a Mockingbird'
put 'library', 'book_1', 'books:author', 'Harper Lee'
put 'library', 'book_1', 'books:isbn', '9780061120084'

put 'library', 'author_1', 'authors:name', 'Harper Lee'
put 'library', 'author_1', 'authors:birthdate', 'April 28, 1926'
put 'library', 'author_1', 'authors:nationality', 'American'

put 'library', 'member_1', 'members:name', 'John Smith'
put 'library', 'member_1', 'members:member_id', '12345'
put 'library', 'member_1', 'members:email', 'john@example.com'


get 'library', 'book_1'
get 'library', 'author_1'
get 'library', 'member_1'
scan 'library'

put 'library', 'book_1', 'books:title', 'To Kill a Mockingbird - Updated Edition'

delete 'library', 'author_1', 'authors:nationality'

