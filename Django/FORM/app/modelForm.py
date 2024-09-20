from django import forms

from .models import User

class UserForm(forms.ModelForm):
    name = forms.CharField(label="Name", min_length=3, max_length=50)
    password = forms.CharField(widget=forms.PasswordInput)
    age = forms.IntegerField(label="Age", min_value=1)
    dateOfBirth = forms.DateField(widget=forms.DateInput(format="%Y-%m-%d", attrs={"type": "date"}), label="Date Of Birth")
    quote = forms.CharField(widget=forms.Textarea)

    class Meta:
        model = User
        fields = "__all__"
        # widget = {
        #     'dateOfBirth': forms.DateInput(
        #         format=('%Y-%m-%d'),
        #         attrs={
        #             'class': 'form-control',
        #             'placeholder': 'input your date of birth',
        #             'type': 'date'
        #         }
        #     )
        # }

        # some of them, is not widget, like charfield, integerfield
        # widgets = {
        #     "name": forms.CharField(label="Name", min_length=3, max_length=50),
        #     "password": forms.PasswordInput(),
        #     "age": forms.IntegerField(label="Age", min_value=1),
        #     "dateOfBirth": forms.DateField(label="Date Of Birth"),
        #     "quote": forms.Textarea(attrs={"cols": 80, "rows": 20}),
        # }

# fields = "__all__"
# fields = ["name", "password", "age", "dateOfBirth", "quote"]