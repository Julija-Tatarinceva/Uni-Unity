from tkinter import *
from tkinter import ttk
import customtkinter
from customtkinter import CTkEntry
from customtkinter import CTkLabel
from customtkinter import CTkButton
from customtkinter import CTkOptionMenu

inventory = {
    '9780743273565': {
        'title': 'The Great Gatsby',
        'author': 'F. Scott Fitzgerald',
        'ISBN': '9780743273565',
        'price': 9.99,
        'quantity_in_stock': 20
    },
    '9780061120084': {
        'title': 'To Kill a Mockingbird',
        'author': 'Harper Lee',
        'ISBN': '9780061120084',
        'price': 12.99,
        'quantity_in_stock': 15
    },
    '9780451524935': {
        'title': '1984',
        'author': 'George Orwell',
        'ISBN': '9780451524935',
        'price': 11.99,
        'quantity_in_stock': 18
    },
    '9780316769488': {
        'title': 'The Catcher in the Rye',
        'author': 'J.D. Salinger',
        'ISBN': '9780316769488',
        'price': 10.49,
        'quantity_in_stock': 12
    },
    '9780156031516': {
        'title': 'To the Lighthouse',
        'author': 'Virginia Woolf',
        'ISBN': '9780156031516',
        'price': 14.99,
        'quantity_in_stock': 9
    },
    '9780060850524': {
        'title': 'Brave New World',
        'author': 'Aldous Huxley',
        'ISBN': '9780060850524',
        'price': 8.99,
        'quantity_in_stock': 25
    },
    '9780141439518': {
        'title': 'Pride and Prejudice',
        'author': 'Jane Austen',
        'ISBN': '9780141439518',
        'price': 13.79,
        'quantity_in_stock': 14
    },
    '9780618260300': {
        'title': 'The Hobbit',
        'author': 'J.R.R. Tolkien',
        'ISBN': '9780618260300',
        'price': 15.99,
        'quantity_in_stock': 17
    },
    '9780307474278': {
        'title': 'The Da Vinci Code',
        'author': 'Dan Brown',
        'ISBN': '9780307474278',
        'price': 9.49,
        'quantity_in_stock': 21
    },
    '9780062315007': {
        'title': 'The Alchemist',
        'author': 'Paulo Coelho',
        'ISBN': '9780062315007',
        'price': 12.99,
        'quantity_in_stock': 20
    }
}

book_entries = [] #used to save references to entries and then delete them from frame before displaying new information

def ChangeView():
    # make different frames appear and disappear
    print("changed")

def ClearGrid():
    i=0
    global book_entries
    for entry in book_entries:
        i+=1
        entry.destroy()

def DisplayBook(book, row):
    col = 0
    for info in book:
        entry = CTkEntry(body, border_width=0)
        entry.insert(END, book[info])
        entry.configure(state='readonly', fg_color="#DCB477", text_color="black", corner_radius=0, justify='center')
        entry.grid(row=row, column=col, pady=5)
        book_entries.append(entry)
        col+=1

def AllBooks():
    global book_entries
    i=2
    for isbn_code, book_info in inventory.items():
        DisplayBook(book_info, i)
        i+=1

def SearchBooks():
    ClearGrid()
    selected_criteria = search_criteria.get()
    search_term = search_bar.get()
    print("looking for ",selected_criteria," containing ", search_term)
    i=2
    if selected_criteria=="ISBN":
        if search_term in inventory:
            DisplayBook(inventory[search_term], i)
        else:
            print("No book found in the database")
        return
    if selected_criteria=="Author":
        for isbn_code, book_info in inventory.items():
            if search_term in book_info["author"]:
                DisplayBook(book_info, i)
                i+=1
        return
    if selected_criteria=="Title":
        for isbn_code, book_info in inventory.items():
            if search_term in book_info["title"]:
                DisplayBook(book_info, i)
                i+=1
        return
        
customtkinter.set_appearance_mode("System")
customtkinter.set_default_color_theme("blue")

win = customtkinter.CTk()  # create main window
win.geometry("800x500")
win.minsize(670, 500)
win.title("Books")
win.config(bg="#B78946")

#creating frame for search bar and buttons
head = customtkinter.CTkFrame(master=win) 
head.configure(fg_color="#B78946", corner_radius=0, border_width=0)
head.pack(side='top')

#creating frame for displaying book informaion
body = customtkinter.CTkFrame(master=win)
body.configure(fg_color="#B78946", corner_radius=0, border_width=0)
body.pack()

search_bar = CTkEntry(head, border_width=0)
search_bar.configure(fg_color="white")
search_bar.grid(row=0, column=0, pady=5, sticky="e")

# Create and place the dropdown menu for search criteria
search_criteria = StringVar(value="ISBN")
criteria_dropdown = CTkOptionMenu(master=head, values=["ISBN", "Author",  "Title"], variable=search_criteria)
criteria_dropdown.configure(width=80, fg_color="#E5A0C0", text_color="black", button_color="#E5A0C0", button_hover_color="#D08DAC")
criteria_dropdown.grid(row=0, column=1, pady=5, sticky="ew")

search_btn = CTkButton(head, text="Search", command=SearchBooks)
search_btn.configure(width=100, fg_color="#E5A0C0", text_color="black", hover_color="#D08DAC")
search_btn.grid(row=0, column=3, pady=20, padx=(10, 100), sticky="w")

delete_btn = CTkButton(head, text="Delete", command=SearchBooks)
delete_btn.configure(width=100, fg_color="#E5A0C0", text_color="black", hover_color="#D08DAC")
delete_btn.grid(row=0, column=4, pady=10, padx=10, sticky="w")

create_btn = CTkButton(head, text="Create", command=SearchBooks)
create_btn.configure(width=100, fg_color="#E5A0C0", text_color="black", hover_color="#D08DAC")
create_btn.grid(row=0, column=5, pady=10, padx=10, sticky="w")

# fg_color="#CB00B8", hover_color="#AE029E" old hues

# used to create table head
headers = ["Title", "Author", "ISBN", "Price", "AmountInStock"]
for col, header in enumerate(headers):
    label = CTkLabel(body, text=header)
    label.configure(text_color="black")
    label.grid(row=1, column = col)

#adjusting size when resizing the window
Grid.columnconfigure(win,0,weight=1)
Grid.columnconfigure(body,1,weight=1)
Grid.columnconfigure(body,2,weight=1)
Grid.columnconfigure(body,3,weight=1)
Grid.columnconfigure(body,4,weight=1)
Grid.columnconfigure(body,5,weight=1)

AllBooks()

win.mainloop()

def AddBook(title, author, isbn, price, quantity):
    if isbn in inventory:
        print("Such ISBN already exists")
    else:
        inventory[isbn] = {
            'title': title,
            'author': author,
            'ISBN': isbn,
            'price': price,
            'quantity_in_stock': quantity
        }
        print(f'Grāmata "{title}" tika pievienota inventāram.')
    
def RemoveBook(isbn):
    if isbn in inventory:
        title = inventory[isbn]["title"]
        inventory.pop(str(isbn))
        print(f"Book {title} removed successfully")
    else:
        print("No such book found in the database")
    
