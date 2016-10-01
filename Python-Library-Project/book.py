#Sumeet Tulsani
from media import Media

class Book(Media):
    def __init__(self,call_number,title,subjects,author,description,publisher,city,year,series,notes):
        Media.__init__(self,call_number,title,subjects,notes)
        self.author = author
        self.description = description
        self.publisher = publisher
        self.city = city
        self.year = year
        self.series = series

    def display(self):
        print ("---------------BOOK-----------------");
        print ("CALL NUMBER::",self.call_number);
        print ("TITLE::",self.title);
        print ("SUBJECTS::",self.subjects);
        print ("AUTHOR::",self.author);
        print ("DESCRIPTION::",self.description);
        print ("PUBLISHER::",self.publisher);
        print ("CITY::",self.city);
        print ("YEAR::",self.year);
        print ("SERIES::",self.series);
        print ("NOTES::",self.notes);

    def compare_other(self,searchby):
        if (self.description.find(searchby) != -1) or  (self.notes.find(searchby) != -1) or (self.year.find(searchby) != -1):
            return True
        else:
            return False
