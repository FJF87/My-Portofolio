from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.urls import reverse
from django import forms

from .models import UserData

import argon2

argonHash = argon2.PasswordHasher(time_cost=50)

class User(forms.Form):
    username = forms.CharField(label="Username", min_length=3)
    password = forms.CharField(label="Password", min_length=10)

# Create your views here.
def index(request):
    return HttpResponseRedirect(reverse("loginApp:login"))

def signIn(request):
    if request.method == "POST":
        getUser = User(request.POST)
        if getUser.is_valid():
            getUserUsername = getUser.cleaned_data["username"]
            getUserPassword = getUser.cleaned_data["password"]

            usernameExist = UserData.objects.filter(username=getUserUsername).exists()
            if usernameExist == False:
                contObj = {
                    "Lowercase": False,
                    "Uppercase": False,
                    "Number": False,
                    "Special-character": False
                }
                for i in getUserPassword:
                    getChar = ord(i)
                    if getChar >= 48 and getChar <= 57:
                        contObj["Number"] = True
                    elif getChar >= 65 and getChar <= 90:
                        contObj["Uppercase"] = True
                    elif getChar >= 97 and getChar <= 122:
                        contObj["Lowercase"] = True
                    else:
                        contObj["Special-character"] = True
                messages = []
                objVal = list(contObj.values())
                objKey = list(contObj.keys())

                i = 0
                for i in range(len(contObj)):
                    if objVal[i] == False:
                        messages.append(f"{objKey[i]} must present in password")

                if len(messages) == 0:
                    # password strong enough - use session
                    # change it to argon2 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    userPass = argonHash.hash(getUserPassword)
                    newUser = UserData.objects.create(username=getUserUsername, password=userPass)
                    newUser.save()
                    request.session["activeUser"] = getUserUsername
                    return render(request, "loginApp/mainPage.html", {
                        "username": request.session["activeUser"]
                    })
                    pass
                else:
                    #password not strong enough
                    return render(request, "loginApp/signIn.html", {
                        "form": getUser,
                        "messages": messages
                    })
                    pass
            else:
                return render(request, "loginApp/signIn.html", {
                    "form": getUser,
                    "message": "Username already exist"
                })
        else:
            return render(request, "loginApp/signIn.html", {
                "form": getUser
            })
    elif "activeUser" in request.session:
        return render(request, "loginApp/mainPage.html", {
            "username": request.session["activeUser"],
            "message": f"you already login as {request.session['activeUser']}"
        })
    else:
        return render(request, "loginApp/signIn.html", {
            "form": User()
        })
    
def login(request):
    if request.method == "POST":
        getUser = User(request.POST)
        if getUser.is_valid():
            getUserUsername = getUser.cleaned_data["username"]
            getUserPassword = getUser.cleaned_data["password"]
            getUserData = UserData.objects.filter(username=getUserUsername).values()
            if getUserData: #if username exist
                # use argon2 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                hashPass = argonHash.hash(getUserPassword)
                try:
                    argonHash.verify(getUserData[0]["password"], getUserPassword)
                    request.session["activeUser"] = getUserUsername
                    return HttpResponseRedirect(reverse("loginApp:mainPage"))
                except:
                    return render(request, "loginApp/login.html", {
                        "form": getUser,
                        "message": f"Your password is incorrect, <br> hashPass: { hashPass } getUserData: { getUserData[0]['password'] }"
                    })
                # if getUserData[0]["password"] == hashPass:
                #     #password correct
                #     request.session["activeUser"] = getUserUsername
                #     return HttpResponseRedirect(reverse("loginApp:mainPage"))
                # else:
                #     return render(request, "loginApp/login.html", {
                #         "form": getUser,
                #         "message": f"Your password is incorrect, <br> hashPass: { hashPass } getUserData: { getUserData[0]['password'] }"
                #     })
            else:
                return render(request, "loginApp/login.html", {
                    "form": getUser,
                    "message": "Username doesn't exist"
                })
        else:
            return render(request, "loginApp/login.html", {
                "form": getUser,
            })
    elif "activeUser" in request.session:
        return render(request, "loginApp/mainPage.html", {
            "username": request.session["activeUser"],
            "message": f"you already login as {request.session['activeUser']}"
        })
    else:
        return render(request, "loginApp/login.html", {
            "form": User()
        })
    
def mainPage(request):
    if "activeUser" in request.session:
        return render(request, "loginApp/mainPage.html", {
            "username": request.session["activeUser"]
        })
    else:
        return render(request, "loginApp/login.html", {
            "form": User(),
            "message": "You have to login first"
        })
    
def logout(request):
    if "activeUser" in request.session:
        request.session.flush()
        return render(request, "loginApp/login.html", {
            "form": User()
        })
    else:
        return render(request, "loginApp/login.html", {
            "form": User(),
            "message": "You have to login first"
        })
    
# username: luke
# password: lukeskywallkeR8@

# hash function from python isn't pure