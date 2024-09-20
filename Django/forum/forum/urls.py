from django.urls import path

from . import views

app_name = "forum"

urlpatterns = [
    path("", views.index, name="index"),
    path("login/", views.login, name="login"),
    path("addForum/", views.addForum, name="addForum"),
    path("showForum/", views.showForum, name="showForum"),
    path("logout/", views.logout, name="logout")
]