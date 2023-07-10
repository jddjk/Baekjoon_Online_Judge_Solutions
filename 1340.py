from datetime import datetime

date_str = input()

date = datetime.strptime(date_str, "%B %d, %Y %H:%M")

now = datetime.now()
start_date = datetime(date.year, 1, 1)
end_date = datetime(date.year + 1, 1, 1)

progress = (date - start_date).total_seconds() / (end_date - start_date).total_seconds() * 100

print(progress)
