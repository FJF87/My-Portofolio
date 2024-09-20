from django.shortcuts import render
from django import forms
from django.http import HttpResponseRedirect
from django.urls import reverse

# defaultTodo = [
#     {
#         "name": "homework",
#         "description": "to hell with it"
#     },
#     {
#         "name": "learn django",
#         "description": "right away!"
#     },
#     {
#         "name": "read book",
#         "description": "what do I wanna read?"
#     }
# ]

class newTodo(forms.Form):
    todoName = forms.CharField(label="New Task")
    todoDescription = forms.CharField(label="New Task's description")

# Create your views here.
def index(request):
    return render(request, "todo/index.html")

def showTodo(request):
    if "todoList" not in request.session:
        request.session["todoList"] = []

    return render(request, "todo/showTodo.html", {
        "todolist": request.session["todoList"]
    })

def addTodo(request):
    if request.method == "POST":
        filledForm = newTodo(request.POST)
        if filledForm.is_valid():
            newTodoObject = {
                "name": filledForm.cleaned_data["todoName"],
                "description": filledForm.cleaned_data["todoDescription"]
            }
            request.session["todoList"] += [newTodoObject]
            return HttpResponseRedirect(reverse("todo:showTodo"))
        else:
            return render(request, "todo/addTodo.html", {
                "form": filledForm
            })

    return render(request, "todo/addTodo.html", {
        "form": newTodo()
    })