#Sumeet Tulsani
from book import Book
from video import Video
from periodic import Periodic
from film import Film
from media import Media
import string
class Searchengine:
    def __init__(self):
        self.cardcatalog = list()
        f = open('book.txt', 'r')
        a = f.readline()
        while a:
            x = a.split('|')
            a = f.readline()
            call_number = x[0]
            title = x[1]
            subjects = x[2]
            author = x[3]
            description = x[4]
            publisher = x[5]
            city = x[6]
            year = x[7]
            series = x[8]
            notes = x[9]
            bk = Book(call_number,title,subjects,author,description,publisher,city,year,series,notes)
            self.cardcatalog.append(bk)
        #f.close()
        f1 = open('periodic.txt', 'r')
        a = f1.readline()
        while a:
            x = a.split('|')
            a = f1.readline()
            call_number = x[0]
            title = x[1]
            subjects = x[2]
            author = x[3]
            description = x[4]
            publisher = x[5]
            publishing_history = x[6]
            series = x[7]
            notes = x[8]
            related_titles = x[9]
            other_forms_of_title = x[10]
            gov_doc_number = x[11]
            pk = Periodic(call_number,title,subjects,author,description,publisher,publishing_history
            ,series,notes,related_titles,other_forms_of_title,gov_doc_number)
            self.cardcatalog.append(pk)
        #f1.close()
        f2 = open('video.txt', 'r')
        a = f2.readline()
        while a:
            x = a.split('|')
            a = f2.readline()
            call_number = x[0]
            title = x[1]
            subjects = x[2]
            description = x[3]
            distributor = x[4]
            notes = x[5]
            series = x[6]
            label = x[7]
            vk = Video(call_number,title,subjects,description,distributor,notes,series,label)
            self.cardcatalog.append(vk)
        #f2.close()
        f3 = open('film.txt', 'r')
        a = f3.readline()
        while a:
            x = a.split('|')
            a = f3.readline()
            call_number = x[0]
            title = x[1]
            subjects = x[2]
            director = x[3]
            notes = x[4]
            year = x[5]
            fk = Film(call_number,title,subjects,director,notes,year)
            self.cardcatalog.append(fk)
        #f3.close()

    def search_by_title(self,title):
        result = list()
        i = 0
        size = len(self.cardcatalog)
        while i != size:
            found = self.cardcatalog[i].compare_title(title)
            if found == True:
                result.append(self.cardcatalog[i])
            i = i + 1
        return result

    def search_by_call_number(self,call_number):
        result = list()
        i = 0
        size = len(self.cardcatalog)
        while i != size:
            found = self.cardcatalog[i].compare_call_number(call_number)
            if found == True:
                result.append(self.cardcatalog[i])
            i = i + 1
        return result
    def search_by_subjects(self,subject):
        result = list()
        i = 0
        size = len(self.cardcatalog)
        while i != size:
            found = self.cardcatalog[i].compare_subject(subject)
            if found == True:
                result.append(self.cardcatalog[i])
            i = i + 1
        return result

    def search_by_other(self,other):
        result = list()
        i = 0
        size = len(self.cardcatalog)
        while i != size:
            found = self.cardcatalog[i].compare_other(other)
            if found == True:
                result.append(self.cardcatalog[i])
            i = i + 1
        return result
