from django.urls import path

from . import views

app_name = "loginApp"

urlpatterns = [
    path('', views.index, name="index"),
    path('signIn/', views.signIn, name="signIn"),
    path('login/', views.login, name="login"),
    path('mainPage/', views.mainPage, name="mainPage"),
    path('logout/', views.logout, name="logout")
]