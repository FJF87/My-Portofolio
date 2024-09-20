# from datetime import datetime, date

from django.shortcuts import render
from django import forms
from django.http import HttpResponseRedirect
from django.urls import reverse

from .models import Notes

class notes(forms.Form):
    title = forms.CharField(label="Title", min_length=1, required=True)
    description = forms.CharField(label="Description", min_length=1, required=True)

# Create your views here.
def homepage(request):
    return render(request, 'notes/homepage.html')

def addNotes(request):
    if request.method == "POST":
        newNotes = notes(request.POST)
        if newNotes.is_valid():
            newTitle = newNotes.cleaned_data["title"]
            newDescription = newNotes.cleaned_data["description"]
            saveNote = Notes.objects.create(title=newTitle, description=newDescription)
            saveNote.save()
            return HttpResponseRedirect(reverse("notes:viewNotes"))
        else:
            return render(request, "notes/addNotes.html", {
                "form": newNotes
            })
    else:
        return render(request, "notes/addNotes.html", {
            "form": notes()
        })

def viewNotes(request):
    getNotes = Notes.objects.all()
    return render(request, "notes/viewNotes.html", {
        "notes": getNotes
    })

# def searchNotes(request):

def deleteNotes(request, noteIndex):
    getNote = Notes.objects.get(pk=noteIndex)
    getNote.delete()
    return HttpResponseRedirect(reverse("notes:viewNotes"))

def editNotes(request, noteIndex):
    getNote = Notes.objects.get(pk=noteIndex)
    if request.method == "POST":
        updatedNote = notes(request.POST)
        if updatedNote.is_valid():
            getNote.title = updatedNote.cleaned_data["title"]
            getNote.description = updatedNote.cleaned_data["description"]
            getNote.save()
            return HttpResponseRedirect(reverse("notes:viewNotes"))
        else:
            return render(request, "notes/editNotes.html", {
                "noteID": noteIndex,
                "note": updatedNote
            })
    else:
        return render(request, "notes/editNotes.html", {
            "noteID": noteIndex,
            # "note": notes(getNote)c
            "note": notes()
        })