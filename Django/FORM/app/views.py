from django.shortcuts import render

from .modelForm import UserForm

# Create your views here.
def index(request):
    if request.method == "POST":
        getUserForm = UserForm(request.POST)
        if getUserForm.is_valid():
            user = {
                # "name": getUserForm.cleaned_data("name"),
                # "password": getUserForm.cleaned_data("password"),
                # "age": getUserForm.cleaned_data("age"),
                # "dateOfBirth": getUserForm.cleaned_data("dateOfBirth"),
                # "quote": getUserForm.cleaned_data("quote")
                "name": request.POST["name"],
                "password": request.POST["password"],
                "age": request.POST["age"],
                "dateOfBirth": request.POST["dateOfBirth"],
                "quote": request.POST["quote"]
            }
            return render(request, "app/index.html", {
                "user": user, # user object
                "form": UserForm()
            })
        else:
            return render(request, "app/index.html", {
                "message": "Please input it correctly",
                "form": getUserForm
            })
    else:
        return render(request, "app/index.html", {
            "form": UserForm()
        })