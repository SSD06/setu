#pragma execution_character_set("utf-8")
#include "setuapi.h"




setuapi::setuapi(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QString  curPath = QDir::currentPath();
	QDir dir(curPath);
	
	QString sub = "色图";
	dir.mkdir(sub);

	timer = new QTimer();
	connect(timer, &QTimer::timeout, this, &setuapi::LoadImage);
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		if (ui.pushButton->text() == "随机色图")
		{
			ui.pushButton->setText("停止获取");
			auto num = ui.spinBox->value();
			auto tag = ui.lineEdit->text();
			int isR18 = 0;
			if (ui.radioButton->isChecked())
			{
				isR18 = 0;
			}
			else if (ui.radioButton_2->isChecked())
			{
				isR18 = 1;
			}
			else if (ui.radioButton_3->isChecked())
			{
				isR18 = 2;
			}
			for (int i = 0; i < num; i++)
			{
				QSharedPointer<huoqu> thread(new huoqu);
				thread->setIsR18(isR18);
				thread->setTag(tag);
				thread->setThreadnum(i + 1);
				connect(thread.get(), &huoqu::jieshu, this, [=](QString filename) {
					QMutexLocker lock(&Mutex_filename);
					Filenames.enqueue(filename);
					});
				Threads.push_back(thread);
			}
			foreach(auto &thread, Threads)
			{
				thread->start();
			}
			timer->start(1000);
		}
		else if (ui.pushButton->text() == "停止获取")
		{

			foreach(auto &thread, Threads)
			{
				thread->setStop(true);
				thread->quit();

			}
			while (true)
			{
				auto stopnum = false;
				foreach(auto &thread, Threads)
				{
					stopnum = stopnum || thread->isRunning();
				}
				if (stopnum == false)
				{
					break;
				}
			}
			Threads.clear();
			timer->stop();
			Filenames.clear();
			ui.pushButton->setText("随机色图");
		}
		});
}
void setuapi::LoadImage()
{

	QMutexLocker lock(&Mutex_filename);

	if (!Filenames.isEmpty())
	{
		QString filename;
		filename = Filenames.dequeue();
		//qDebug() << filename;
		QImage Image;
		if(Image.load(filename))
		{ 
		QPixmap pixmap = QPixmap::fromImage(Image);

		int with = ui.label->width();
		int height = ui.label->height();

		QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

		ui.label->setPixmap(fitpixmap);

		ui.label->setScaledContents(true);
		}
	}
}
