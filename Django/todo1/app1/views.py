from django.shortcuts import render
from django.http import HttpResponse

menulist = [
    {
        "name": "spagety",
        "type": "food",
        "price": 12.00
    },
    {
        "name": "bread",
        "type": "food",
        "price": 8.00
    },
    {
        "name": "coffee",
        "type": "beverage",
        "price": 5.00
    },
    {
        "name": "sandwich",
        "type": "food",
        "price": 10.00
    }
]

# Create your views here.
def index(request):
    return HttpResponse("<h1>Welcome to app 1</h1>")

def greet(request, name):
    greeting = f"<h1>hello {name}</h1>"
    return HttpResponse(greeting)

def menus(request):
    return render(request, "app1/menus.html", {
        "menulist": menulist
    })