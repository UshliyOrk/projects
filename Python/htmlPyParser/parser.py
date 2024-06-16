import requests
from bs4 import BeautifulSoup
from datetime import date, timedelta

class Parser:
	def __init__(self):
		url= "https://cbr.ru/curreNcy_base/daily/?UniDbQuery.Posted=True&UniDbQuery.To="
		d = date.today()
		d = d.strftime("%d.%m.%Y")
		today_url = url+d
		d = (date.today()-timedelta(days=1)).strftime("%d.%m.%Y")
		yesterday_url = url+d
		response = requests.get(today_url)
		self.soup_today = BeautifulSoup(response.content, "html.parser")
		response = requests.get(yesterday_url)
		self.soup_yesterday = BeautifulSoup(response.content, "html.parser")

	def get_date(self):
		dateToday = self.soup_today.find("button", class_="datepicker-filter_button").get_text()
		dateYesterday = self.soup_yesterday.find("button", class_="datepicker-filter_button").get_text()
		return [dateToday, dateYesterday]

	def get_currency(self):
		currency={}
		currency["today"] = self.soup_today.find("table", class_="data").get_text()
		currency["today"] = currency["today"].split("\n\n")[2:-1]
		currency["yesterday"] = self.soup_yesterday.find("table", class_="data").get_text()
		currency["yesterday"] = currency["yesterday"].split("\n\n")[2:-1]
		cur = []
		for i in currency["today"]: 
			cur.append(i.split("\n")[2:])
		currency["today"] = cur
		for i in currency["yesterday"]: 
			cur.append(i.split("\n")[2:])
		currency["yesterday"] = cur
		return currency

	def get_currency_byDate(self, date):
		currency = []
		url = f"https://cbr.ru/curreNcy_base/daily/?UniDbQuery.Posted=True&UniDbQuery.To={date}"
		soup = BeautifulSoup(requests.get(url).content, "html.parser")
		pars = soup.find("table", class_="data").get_text()
		pars = pars.split("\n\n")[2:-1]
		for i in pars:
			currency.append(i.split("\n")[2:])
		return currency


if __name__ == "__main__":
	parser = Parser()
	d = parser.get_date()
	cur = parser.get_currency()

	print("курсы валют на", d[0],"\n")
	for i in cur["today"]:
		print(" ".join(i)+" руб")
	print("\n"+"-"*30+"\n")
	print("курсы валют на", d[1],"\n")
	for i in cur["yesterday"]:
		print(" ".join(i)+" руб")

	date = "14.03.2024"
	print("\n"+"-"*30+"\n")
	print(f"курсы валют на {date}")
	for i in parser.get_currency_byDate(date):
		print(" ".join(i)+" руб")
