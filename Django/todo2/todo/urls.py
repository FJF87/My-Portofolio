from django.urls import path

from . import views

app_name = "todo"

urlpatterns = [
    path('', views.index, name="index"),
    path('showTodo', views.showTodo, name="showTodo"),
    path('addTodo', views.addTodo, name="addTodo")
]