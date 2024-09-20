from django.shortcuts import render
from django import forms
from django.http import HttpResponseRedirect
from django.urls import reverse

from datetime import date, datetime

# there is problem with user session of "activeUser"

currentForum = []

class newUser(forms.Form):
    name = forms.CharField(label="name", min_length=3)

class newForum(forms.Form):
    comment = forms.CharField(label="comment", min_length=3)

# Create your views here.
def index(request):
    if "activeUser" not in request.session:
        # request.session["activeUser"] = ""
        return HttpResponseRedirect(reverse("forum:login"))
    else:
        return HttpResponseRedirect(reverse("forum:addForum"))

def login(request):
    # if "activeUser" not in request.session:

    if request.method == "POST":
        activeUser = newUser(request.POST)
        if activeUser.is_valid():
            userSession = activeUser.cleaned_data["name"]
            request.session['activeUser'] = userSession
            return HttpResponseRedirect(reverse("forum:showForum"))
        else:
            return render(request, "forum/login.html", {
                "message": "invalid input",
                "form": activeUser
            })
    else:
        # request.session["activeUser"] = False
        return render(request, "forum/login.html", {
            "message": "",
            "form": newUser()
        })
        
    # else:
    #     activeUser = request.session["activeUser"]
    #     return render(request, "forum/showForum.html", {
    #         "message": f"you have active session as {activeUser}",
    #         "form": currentForum
    #     })
    
def showForum(request):
    return render(request, "forum/showForum.html", {
        "forum": currentForum
    })
    
def addForum(request):
    if "activeUser" in request.session:
        if request.method == "POST":
            activeForm = newForum(request.POST)
            if activeForm.is_valid():
                activeName = request.session["activeUser"]
                activeComment = activeForm.cleaned_data["comment"]
                currentDate = datetime.now()
                currentTime = currentDate.strftime('%H:%M:%S')
                currentDate = date.today()
                currentForum.append({
                    "name": activeName,
                    "date": currentDate,
                    "time": currentTime,
                    "comment": activeComment
                })
                return HttpResponseRedirect(reverse("forum:showForum"))
            else:
                return render(request, "forum/addForum.html", {
                    "form": activeForm
                })
        else:
            return render(request, "forum/addForum.html", {
                "form": newForum()
            })
    else:
        # return render(request, "forum/login.html")
        return render(request, "forum/login.html", {
            "message": "You need to login first",
            "form": newUser()
        })
    
def logout(request):
    if "activeUser" in request.session:
        # del request.session["activeUser"]
        request.session.flush()
    return HttpResponseRedirect(reverse("forum:index"))