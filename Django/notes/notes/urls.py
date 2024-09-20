from django.urls import path

from . import views

app_name = "notes"

urlpatterns = [
    path('', views.homepage, name="homepage"),
    path('addNotes/', views.addNotes, name="addNotes"),
    path('viewNotes/', views.viewNotes, name="viewNotes"),
    path('deleteNotes/<int:noteIndex>', views.deleteNotes, name="deleteNotes"),
    path('editNotes/<int:noteIndex>', views.editNotes, name="editNotes")
]