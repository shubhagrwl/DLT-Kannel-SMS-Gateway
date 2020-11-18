#include "gwlib/gwlib.h"

#if defined(HAVE_MYSQL) || defined(HAVE_SDB)

#define SQLBOX_MYSQL_CREATE_LOG_TABLE "CREATE TABLE IF NOT EXISTS %S ( \
sql_id BIGINT(20) NOT NULL AUTO_INCREMENT PRIMARY KEY, \
momt ENUM('MO', 'MT', 'DLR') NULL, sender VARCHAR(20) NULL, \
receiver VARCHAR(20) NULL, udhdata BLOB NULL, msgdata TEXT NULL, \
time BIGINT(20) NULL, smsc_id VARCHAR(255) NULL, service VARCHAR(255) NULL, \
account VARCHAR(255) NULL, id BIGINT(20) NULL, sms_type BIGINT(20) NULL, \
mclass BIGINT(20) NULL, mwi BIGINT(20) NULL, coding BIGINT(20) NULL, \
compress BIGINT(20) NULL, validity BIGINT(20) NULL, deferred BIGINT(20) NULL, \
dlr_mask BIGINT(20) NULL, dlr_url VARCHAR(255) NULL, pid BIGINT(20) NULL, \
alt_dcs BIGINT(20) NULL, rpi BIGINT(20) NULL, charset VARCHAR(255) NULL, \
boxc_id VARCHAR(255) NULL, binfo VARCHAR(255) NULL, meta_data TEXT, \
priority BIGINT(20) NULL, foreign_id VARCHAR(255) NULL)"

#define SQLBOX_MYSQL_CREATE_INSERT_TABLE "CREATE TABLE IF NOT EXISTS %S ( \
sql_id BIGINT(20) NOT NULL AUTO_INCREMENT PRIMARY KEY, \
momt ENUM('MO', 'MT') NULL, sender VARCHAR(20) NULL, \
receiver VARCHAR(20) NULL, udhdata BLOB NULL, msgdata TEXT NULL, \
time BIGINT(20) NULL, smsc_id VARCHAR(255) NULL, service VARCHAR(255) NULL, \
account VARCHAR(255) NULL, id BIGINT(20) NULL, sms_type BIGINT(20) NULL, \
mclass BIGINT(20) NULL, mwi BIGINT(20) NULL, coding BIGINT(20) NULL, \
compress BIGINT(20) NULL, validity BIGINT(20) NULL, deferred BIGINT(20) NULL, \
dlr_mask BIGINT(20) NULL, dlr_url VARCHAR(255) NULL, pid BIGINT(20) NULL, \
alt_dcs BIGINT(20) NULL, rpi BIGINT(20) NULL, charset VARCHAR(255) NULL, \
boxc_id VARCHAR(255) NULL, binfo VARCHAR(255) NULL, meta_data TEXT, \
priority BIGINT(20) NULL, foreign_id VARCHAR(255) NULL)"

#define SQLBOX_MYSQL_SELECT_QUERY "SELECT sql_id, momt, sender, receiver, udhdata, \
msgdata, time, smsc_id, service, account, id, sms_type, mclass, mwi, coding, \
compress, validity, deferred, dlr_mask, dlr_url, pid, alt_dcs, rpi, \
charset, boxc_id, binfo, meta_data, priority, pe_id FROM %S LIMIT 0,1"

#define SQLBOX_MYSQL_SELECT_LIST_QUERY "SELECT sql_id, momt, sender, receiver, udhdata, \
msgdata, time, smsc_id, service, account, id, sms_type, mclass, mwi, coding, \
compress, validity, deferred, dlr_mask, dlr_url, pid, alt_dcs, rpi, \
charset, boxc_id, binfo, meta_data, priority, pe_id FROM %S LIMIT 0,%ld"

#define SQLBOX_MYSQL_INSERT_QUERY "INSERT INTO %S ( sql_id, momt, sender, \
receiver, udhdata, msgdata, time, smsc_id, service, account, sms_type, \
mclass, mwi, coding, compress, validity, deferred, dlr_mask, dlr_url, \
pid, alt_dcs, rpi, charset, boxc_id, binfo, meta_data, priority, foreign_id ) VALUES ( \
NULL, %S, %S, %S, %S, %S, %S, %S, %S, %S, %S, %S, %S, %S, %S, %S, %S, \
%S, %S, %S, %S, %S, %S, %S, %S, %S, %S, %S)"

#define SQLBOX_MYSQL_INSERT_LIST_QUERY "INSERT INTO %S ( sql_id, momt, sender, \
receiver, udhdata, msgdata, time, smsc_id, service, account, sms_type, \
mclass, mwi, coding, compress, validity, deferred, dlr_mask, dlr_url, \
pid, alt_dcs, rpi, charset, boxc_id, binfo, meta_data, priority, foreign_id ) VALUES %S"

#define SQLBOX_MYSQL_DELETE_QUERY "DELETE FROM %S WHERE sql_id = %S"
#define SQLBOX_MYSQL_DELETE_LIST_QUERY "DELETE FROM %S WHERE sql_id in (%S)"

#endif /* HAVE_MYSQL || HAVE_SDB */

#ifdef HAVE_MYSQL
#include "gw/msg.h"
#include "sqlbox_sql.h"
void sql_save_msg(Msg *msg, Octstr *momt);
Msg *mysql_fetch_msg();
void sql_shutdown();
struct server_type *sqlbox_init_mysql(Cfg* cfg);
#ifndef sqlbox_mysql_c
extern
#endif
Octstr *sqlbox_id;
#endif
