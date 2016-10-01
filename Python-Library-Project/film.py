#Sumeet Tulsani
from media import Media

class Film(Media):
    def __init__(self,call_number,title,subjects,director,notes,year):
        Media.__init__(self,call_number,title,subjects,notes)
        self.director = director
        self.year = year

    def display(self):
        print ("---------------FILM-----------------");
        print ("CALL NUMBER::",self.call_number);
        print ("TITLE::",self.title);
        print ("SUBJECTS::",self.subjects);
        print ("DIRECTOR::",self.director);
        print ("NOTES::",self.notes);
        print ("YEAR::",self.year);

    def compare_other(self,searchby):
        if (self.director.find(searchby) != -1) or  (self.notes.find(searchby) != -1) or (self.year.find(searchby) != -1):
            return True
        else:
            return False
