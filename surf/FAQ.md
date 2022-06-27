# Frequently Asked Questions

## Surf is starting up slowly. What might be causing this?

The first suspect for such behaviour is the plugin handling. Run surf on
the commandline and see if there are errors because of “nspluginwrapper”
or failed RPCs to them. If that is true, go to ~/.mozilla/plugins and
try removing stale links to plugins not on your system anymore. This
will stop surf from trying to load them.

