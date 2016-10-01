#Sumeet Tulsani
from media import Media

class Periodic(Media):
    def __init__(self,call_number,title,subjects,author,description,publisher,publishing_history,series,notes,related_titles,other_forms_of_title,gov_doc_number):
        Media.__init__(self,call_number,title,subjects,notes)
        self.author = author
        self.description = description
        self.publisher = publisher
        self.publishing_history = publishing_history
        self.series = series
        self.related_titles = related_titles
        self.other_forms_of_title = other_forms_of_title
        self.gov_doc_number = gov_doc_number

    def display(self):
        print ("---------------PERIODIC-----------------");
        print ("CALL NUMBER::",self.call_number);
        print ("TITLE::",self.title);
        print ("SUBJECTS::",self.subjects);
        print ("AUTHOR::",self.author);
        print ("DESCRIPTION::",self.description);
        print ("PUBLISHER::",self.publisher);
        print ("PUBLISHING_HISTORY::",self.publishing_history);
        print ("SERIES::",self.series);
        print ("NOTES::",self.notes);
        print ("RELATED_TITLES::",self.related_titles);
        print ("OTHER_FORMS_OF_TITLE::",self.other_forms_of_title);
        print ("GOV_DOC_NUMBER::",self.gov_doc_number);

    def compare_other(self,searchby):
        if (self.description.find(searchby) != -1) or  (self.notes.find(searchby) != -1) or (self.series.find(searchby) != -1) or (self.related_titles.find(searchby) != -1):
            return True
        else:
            return False
