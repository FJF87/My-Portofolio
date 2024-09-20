from datetime import datetime, date

dateNow = datetime.now();
timeNow = dateNow.strftime('%H:%M:%S')

print(date.today());
print(timeNow);