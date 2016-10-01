#Sumeet Tulsani
class Media:
    def __init__(self,a,b,c,d):
        self.call_number = a;
        self.title = b;
        self.subjects = c;
        self.notes = d;

    def display():
        pass

    def compare_title(self,searchby):
        if self.title.find(searchby) != -1:
            return True
        else:
            return False

    def compare_call_number(self,searchby):
        if self.call_number.find(searchby) != -1:
            return True
        else:

            return False

    def compare_subject(self,searchby):
        if self.subjects.find(searchby) != -1:
            return True
        else:
            return False

    def compare_other(searchby):
        pass
