# Port Forwarding Example

## Goals:

- An example of the peer-to-peer connection between two computers behind private networks (no intermediary server)
- Socket programming with Boost Asio C++ library
- Experimenting with port forwarding in action

### Pros:

- No third party server is needed (Although the test program is server-client-based, it can be modified to other models)
- Messaging even between two peers in private networks

### Cons:

- Manual manipulation of access point configurations (requires both access and knowledge)

## DISCLAIMER:

Secure communication is not guaranteed. 
The author(s) is not liable for any interception or loss of data.
For secure messaging, consider implementing an encryption/decryption scheme like HTTP.

## Dependencies

- C++ 11
- CMake
- Boost Asio (boost system and pthread libraries)

## Make

## Testing

### Localhost

### Local Network
