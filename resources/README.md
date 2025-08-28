# Resources

This directory contains application resources including icons, images, translations, and Qt resource files.

## Directory Structure

```
resources/
├── icons/            # Application icons (16x16, 32x32, 64x64, etc.)
├── images/           # Images used in the UI
├── translations/     # Internationalization files (.ts/.qm)
└── personaldevcontrol.qrc  # Qt resource file
```

## Adding Resources

1. Place files in appropriate subdirectories
2. Update `personaldevcontrol.qrc` to include new resources
3. Use Qt resource system syntax in code: `":/path/to/resource"`

## Icon Guidelines

- Provide multiple sizes: 16x16, 32x32, 48x48, 64x64, 128x128
- Use SVG format when possible for scalability
- Follow system icon guidelines for consistency

## Translation Support

The application supports internationalization using Qt's translation system:
- Source language: English (en)
- Planned translations: Portuguese (pt_BR), Spanish (es)

## Qt Resource File

The `personaldevcontrol.qrc` file defines the resource hierarchy used by the application.