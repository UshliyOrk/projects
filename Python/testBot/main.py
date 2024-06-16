import telebot as tb
from sys import exit
from plot import Plotter
Plotter = Plotter()

bot = tb.TeleBot('6389887084:AAEMJQnYlzeSZYCdZGPN0ZJf5mEVBaZIiqw')

@bot.message_handler(commands = ["stop"])
def stop(message):
	print("exit code 0")
	bot.send_message(message.from_user.id, "бот успешно выключен")
	exit(0)

@bot.message_handler(commands=["start"])
def send_some_info(message):
	global mode
	mode = '1'
	markup = tb.types.InlineKeyboardMarkup()
	btn1 = tb.types.InlineKeyboardButton(text="тыкай срочно!!!", url="https://ushliyork.github.io/testSite/")
	markup.add(btn1)
	bot.send_message(message.from_user.id, "по кнопке можно перейти на супер-сайт", reply_markup = markup)

@bot.message_handler()
def answ(message):
	fnc1, fnc2 = message.text.split()
	print(fnc1, fnc2)
	Plotter.functions(fnc1, fnc2)
	Plotter.funcPlot()
	bot.send_photo(message.from_user.id,"plt.png" )

bot.polling(none_stop=True, interval=0)
