select avg(energy) as avg from songs where artist_id in (select id from artists where name = 'Drake');
