select avg(rating) as avg from ratings where movie_id in (select id from movies where year = '2012'); 
