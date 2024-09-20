from django.db import models

# Create your models here.
class User(models.Model):
    name = models.CharField(max_length=50)
    password = models.CharField(max_length=30)
    age = models.PositiveIntegerField()
    dateOfBirth = models.DateField()
    quote = models.CharField(max_length=100)