/* See LICENSE file for copyright and license details. */

/* battery */
const char *battery_perc(const char *);
const char *battery_state(const char *);
const char *battery_remaining(const char *);

/* cpu */
const char *cpu_freq(void);
const char *cpu_perc(void);

/* datetime */
const char *datetime(const char *fmt);

/* disk */
const char *disk_free(const char *path);
const char *disk_perc(const char *path);
const char *disk_total(const char *path);
const char *disk_used(const char *path);

/* entropy */
const char *entropy(void);

/* hostname */
const char *hostname(void);

/* ip */
const char *ipv4(const char *interface);
const char *ipv6(const char *interface);

/* kernel_release */
const char *kernel_release(void);

/* keyboard_indicators */
const char *keyboard_indicators(void);

/* keymap */
const char *keymap(void);

/* load_avg */
const char *load_avg(void);

/* netspeeds */
const char *netspeed_rx(const char *interface);
const char *netspeed_tx(const char *interface);

/* num_files */
const char *num_files(const char *path);

/* ram */
const char *ram_free(void);
const char *ram_perc(void);
const char *ram_total(void);
const char *ram_used(void);

/* run_command */
const char *run_command(const char *cmd);

/* separator */
const char *separator(const char *separator);

/* swap */
const char *swap_free(void);
const char *swap_perc(void);
const char *swap_total(void);
const char *swap_used(void);

/* temperature */
const char *temp(const char *);

/* uptime */
const char *uptime(void);

/* user */
const char *gid(void);
const char *username(void);
const char *uid(void);

/* volume */
const char *vol_perc(const char *card);

/* wifi */
const char *wifi_perc(const char *interface);
const char *wifi_essid(const char *interface);
