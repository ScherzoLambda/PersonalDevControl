# Controllers

This directory contains controller classes that handle the interaction between the UI and core business logic.

## Planned Controllers

- `TaskController` - Manage task operations (create, update, delete)
- `UserController` - Handle user authentication and profile management
- `TimerController` - Control time tracking functionality

## Structure

```cpp
// Example controller interface
class IController {
public:
    virtual ~IController() = default;
    virtual bool initialize() = 0;
    virtual void cleanup() = 0;
};
```

Controllers will follow the Model-View-Controller pattern to separate concerns and improve maintainability.