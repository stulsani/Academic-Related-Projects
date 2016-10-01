#Sumeet Tulsani
from media import Media

class Video(Media):
    def __init__(self,call_number,title,subjects,description,distributor,notes,series,label):
        Media.__init__(self,call_number,title,subjects,notes)
        self.description = description
        self.distributor = distributor
        self.series = series
        self.label = label

    def display(self):
        print ("---------------VIDEO-----------------");
        print ("CALL NUMBER::",self.call_number);
        print ("TITLE::",self.title);
        print ("SUBJECTS::",self.subjects);
        print ("DESCRIPTION::",self.description);
        print ("DISTRIBUTOR::",self.distributor);
        print ("SERIES::",self.series);
        print ("LABEL::",self.label);

    def compare_other(self,searchby):
        if (self.description.find(searchby) != -1) or  (self.notes.find(searchby) != -1) or (self.distributor.find(searchby) != -1):
            return True
        else:
            return False
