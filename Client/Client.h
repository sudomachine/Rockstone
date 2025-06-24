
#pragma once

#include "ClientEvent.h"

#include <memory>
#include <string>

namespace server {
	class Packet;
}

class Player;
class IO;
class Requests;

class Client final
{
public:
	explicit Client(std::shared_ptr<IO> io);
	~Client();

	void disconnect() const;
	void send(std::shared_ptr<server::Packet> packet) const;
	void on_event(const ClientEvent &event);

private:
	std::shared_ptr<IO> io;
	std::shared_ptr<Requests> requests;
	std::shared_ptr<Player> player;

	[[nodiscard]] auto get_ip() const -> IP;

	void on_packet(std::shared_ptr<server::Packet> packet);

	// Примеры обработчиков пакетов
	void params_set(std::shared_ptr<server::Packet> packet) const;
	void buy(std::shared_ptr<server::Packet> packet);
	void login(std::shared_ptr<server::Packet> packet);
};