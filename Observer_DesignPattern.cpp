#include <iostream>
#include <string>
#include <map>

using namespace std;

class Channel;

class Publisher
{
public:
	Publisher(string item)
	{
		cout << "PublisherItem Created: " << item.c_str() << endl;
	}
	void subscribe(string channelName, Channel* channelPtr)
	{
		subscriberList.insert(pair<string, Channel*> (channelName, channelPtr));
	}
	void unsubscribe(string channelName)
	{
		auto itemItr = subscriberList.find(channelName);
		subscriberList.erase(itemItr);
	}

protected:
	void broadcast(string info);
	
private:
	map <string, Channel*> subscriberList;
};


class Election : public Publisher
{
public:
	Election() : Publisher("Election Created")
	{

	}
	void setNews(string newsIp)
	{
		broadcast(newsIp);
	}
};

class Entertainment : public Publisher
{
public:
	Entertainment() : Publisher("Entertainment Created")
	{

	}
	void setNews(string newsIp)
	{
		broadcast(newsIp);
	}
};

class Sports : public Publisher
{
public:
	Sports() : Publisher("Sports Created")
	{

	}
	void setNews(string newsIp)
	{
		broadcast(newsIp);
	}
};


//-------------------------------------------------------

class Channel
{
public:
	Channel(string name)
	{
		cout << "Channel Created: " << name.c_str() << endl;
	}

	virtual void notify(string news) = 0;
};

class zee : public Channel
{
public:
	zee(string name) : Channel(name)
	{

	}

	void notify(string news)
	{
		cout << "ZEE Notification: " << news.c_str() << endl;
	}
};

class ndtv : public Channel
{
public:
	ndtv(string name) : Channel(name)
	{

	}

	void notify(string news)
	{
		cout << "NDTV Notification: " << news.c_str() << endl;
	}
};

class espn : public Channel
{
public:
	espn(string name) : Channel(name)
	{

	}

	void notify(string news)
	{
		cout << "ESPN Notification: " << news.c_str() << endl;
	}
};

class sony : public Channel
{
public:
	sony(string name) : Channel(name)
	{

	}

	void notify(string news)
	{
		cout << "SONY Notification: " << news.c_str() << endl;
	}
};

//-----------------------------------------------------------------

void Publisher::broadcast(string info)
{
	auto subscriberListItr = subscriberList.begin();
	cout << "------- Broadcast Starts: " << info.c_str() << " -------" << endl;
	while (subscriberListItr != subscriberList.end())
	{
		subscriberListItr->second->notify(info);
		subscriberListItr++;
	}
	cout << "------- Broadcast Ends -------" << endl;
}

//-----------------------------------------------------------------

int main4()
{
	zee zeetv("ZEE TV");
	ndtv ndtvChannel("NDTV");
	espn espnLive("ESPN");
	sony sonytv("SONY");

	Election ElectionNews;
	Entertainment EntertainmentNews;
	Sports SportsNews;

	ElectionNews.subscribe("ZEE TV", &zeetv);
	ElectionNews.subscribe("NDTV", &ndtvChannel);

	EntertainmentNews.subscribe("ZEE TV", &zeetv);
	EntertainmentNews.subscribe("SONY", &sonytv);

	SportsNews.subscribe("ESPN", &espnLive);

	ElectionNews.setNews("Narendra Modi is set to get Second Term as PM");
	EntertainmentNews.setNews("Salman Khan gets Married");
	SportsNews.setNews("India Wins the World Cup");
	return 0;
}