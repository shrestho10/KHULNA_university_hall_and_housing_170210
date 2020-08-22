 
<div class="row">
	<div class="col-sm-12">
		<?php
			//TODO: check whether routing is active
			if(isset($page) && apply_routing($page)){

				//echo 'test again:'.$page;
				
				include $_SERVER['DOCUMENT_ROOT'] . '/housing/' . $page;
			}	
		?>
	</div>
</div>
