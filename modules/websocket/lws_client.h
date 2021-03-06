/*************************************************************************/
/*  lws_client.h                                                         */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2018 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2018 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef LWSCLIENT_H
#define LWSCLIENT_H

#ifndef JAVASCRIPT_ENABLED

#include "core/error_list.h"
#include "lws_helper.h"
#include "lws_peer.h"
#include "websocket_client.h"

class LWSClient : public WebSocketClient {

	GDCIIMPL(LWSClient, WebSocketClient);

	LWS_HELPER(LWSClient);

public:
	Error connect_to_host(String p_host, String p_path, uint16_t p_port, bool p_ssl, PoolVector<String> p_protocol = PoolVector<String>());
	Ref<WebSocketPeer> get_peer(int p_peer_id) const;
	void disconnect_from_host();
	IP_Address get_connected_host() const;
	uint16_t get_connected_port() const;
	virtual ConnectionStatus get_connection_status() const;
	virtual void poll();

	LWSClient();
	~LWSClient();
};

#endif // JAVASCRIPT_ENABLED

#endif // LWSCLIENT_H
