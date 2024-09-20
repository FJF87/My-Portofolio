from django.shortcuts import render
from django import forms
from django.http import HttpResponseRedirect
from django.urls import reverse

class newTodo(forms.Form):
    todoName = forms.CharField(label="New Todo Name")
    todoDescription = forms.CharField(label="New Todo Description")

# Create your views here.
def index(request):
    return render(request, "todo/index.html")

def showTodo(request):
    if "todoList" not in request.session:
        request.session["todoList"] = []

    return render(request, "todo/showTodo.html", {
        "todoList": request.session["todoList"]
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