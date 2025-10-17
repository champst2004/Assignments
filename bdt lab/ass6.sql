create table server_metrics(timestamp timestamp, server_id decimal(10, 2), cpu_usage decimal(10, 2), 
          memory_usage decimal(10, 2), disk_usage decimal(10, 2), network_traffic decimal(10, 2)) 
          row format delimited fields terminated by ',' tblproperties("skip.header.line.count"="1");

load data local inpath "/home/cloudera/server.csv" into table server_metrics;

select * from server_metrics;

create table server_transformed as
SELECT
  server_id,
  timestamp,
  split(timestamp, ' ')[0] as date,
  split(split(timestamp, ' ')[1], ':')[0] as hour,
  round(cpu_usage, 2) as cpu_usage,
  round(memory_usage, 2) as memory_usage,
  round(disk_usage, 2) as disk_usage,
  round(network_traffic, 2) as network_traffic
from server_metrics;

select * from server_transformed;

select server_id, avg(cpu_usage) as avg_cpu, avg(memory_usage) as avg_memory, avg(disk_usage) as avg_disk, avg(network_traffic) as avg_network
from server_transformed
group by server_id;

select server_id, avg(cpu_usage) as avg_cpu
from server_transformed
group by server_id
order by avg_cpu asc
limit 1;

select hour, avg(network_traffic) as avg_traffic
from server_transformed
group by hour
order by avg_traffic desc
limit 1;

select date, avg(memory_usage) AS avg_memory
from server_transformed
where server_id = 1
group by date
order by date;