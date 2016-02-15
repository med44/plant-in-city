
<!DOCTYPE HTML>
<head>
<title>Plant-in City</title>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/zepto/1.1.6/zepto.min.js"></script>
<link href="bootstrap.min.css" rel="stylesheet">
<link href="style.css" rel="stylesheet">
<link rel="stylesheet" href="fonts/font-awesome.min.css">
<meta name="viewport" content="width=device-width, initial-scale=1">
<!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
	    <script src="jquery.min.js"></script>
	    <!-- Include all compiled plugins (below), or include individual files as needed -->
	    <script src="bootstrap.min.js"></script>
</head>

<body>
<div class="container col-md-12 col-sm-12 col-xs-12">
	<div class="row">
		<div class="topBar col-md-12 col-sm-12 col-xs-12">				
			<div class="col-md-8 col-sm-8 col-xs-8">
				<div class="textLogo">Plant-in City</div>		
			</div>				
		</div>
	</div>

	<div class="row">
		<i class="fa fa-clock-o"></i> &nbsp
		<?php
			date_default_timezone_set('America/New_York');
			echo date("D j M Y H:i:s T") . "<br>";
		?>
	</div>

	<form name="msgform">
		<div class="row">
				<h4><i class="fa fa-lightbulb-o"></i> &nbsp Lighting</h4>
		</div>
		<div class="row">
			<div class="col-md-4 col-sm-4 col-xs-4">
				<p>Light every
			</div>
			<div class="col-md-8 col-sm-8 col-xs-8">
				<select name="LI">  <!-- LIGHT INTERVAL -->
					<option value="0">0</option>
					<option value="1">1</option>
					<option value="2">2</option>
					<option value="3">3</option>
					<option value="4">4</option>
					<option value="5">5</option>
					<option value="6">6</option>
					<option value="7">7</option>
				</select> day(s)</p>
			</div>
		</div>
		<div class="row">	
			<div class="col-md-4 col-sm-4 col-xs-4">

				<p>Start time (hh:mm)
			</div>

			 <div class="col-md-8 col-sm-8 col-xs-8">
				<select name="LH">  <!-- LIGHT HOUR -->
					<option value="00">00</option>
					<option value="01">01</option>
					<option value="02">02</option>
					<option value="03">03</option>
					<option value="04">04</option>
					<option value="05">05</option>
					<option value="06">06</option>
					<option value="07">07</option>
					<option value="08">08</option>
					<option value="09">09</option>
					<option value="10">10</option>
					<option value="11">11</option>
					<option value="12">12</option>
					<option value="13">13</option>
					<option value="14">14</option>
					<option value="15">15</option>
					<option value="16">16</option>
					<option value="17">17</option>
					<option value="18">18</option>
					<option value="19">19</option>
					<option value="20">20</option>
					<option value="21">21</option>
					<option value="22">22</option>
					<option value="23">23</option>
				</select> 
				:
				<select name="LM">  <!-- LIGHT MINUTE -->
					<option value="00">00</option>
					<option value="01">01</option>
					<option value="02">02</option>
					<option value="03">03</option>
					<option value="04">04</option>
					<option value="05">05</option>
					<option value="06">06</option>
					<option value="07">07</option>
					<option value="08">08</option>
					<option value="09">09</option>
					<option value="10">10</option>
					<option value="11">11</option>
					<option value="12">12</option>
					<option value="13">13</option>
					<option value="14">14</option>
					<option value="15">15</option>
					<option value="16">16</option>
					<option value="17">17</option>
					<option value="18">18</option>
					<option value="19">19</option>
					<option value="20">20</option>
					<option value="21">21</option>
					<option value="22">22</option>
					<option value="23">23</option>
					<option value="24">24</option>
					<option value="25">25</option>
					<option value="26">26</option>
					<option value="27">27</option>
					<option value="28">28</option>
					<option value="29">29</option>
					<option value="30">30</option>
					<option value="31">31</option>
					<option value="32">32</option>
					<option value="33">33</option>
					<option value="34">34</option>
					<option value="35">35</option>
					<option value="36">36</option>
					<option value="37">37</option>
					<option value="38">38</option>
					<option value="39">39</option>
					<option value="40">40</option>
					<option value="41">41</option>
					<option value="42">42</option>
					<option value="43">43</option>
					<option value="44">44</option>
					<option value="45">45</option>
					<option value="46">46</option>
					<option value="47">47</option>
					<option value="48">48</option>
					<option value="49">49</option>
					<option value="50">50</option>
					<option value="51">51</option>
					<option value="52">52</option>
					<option value="53">53</option>
					<option value="54">54</option>
					<option value="55">55</option>
					<option value="56">56</option>
					<option value="57">57</option>
					<option value="58">58</option>
					<option value="59">59</option>
				</select></p>
			</div>
		</div>

		<div class="row">	
			<div class="col-md-4 col-sm-4 col-xs-4">
				<p>Duration (hh:mm)
			</div> 
			<div class="col-md-8 col-sm-8 col-xs-8">
				<select name="LDH">  <!-- LIGHT DURATION HOUR -->
					<option value="00">00</option>
					<option value="01">01</option>
					<option value="02">02</option>
					<option value="03">03</option>
					<option value="04">04</option>
					<option value="05">05</option>
					<option value="06">06</option>
					<option value="07">07</option>
					<option value="08">08</option>
					<option value="09">09</option>
					<option value="10">10</option>
					<option value="11">11</option>
					<option value="12">12</option>
					<option value="13">13</option>
					<option value="14">14</option>
					<option value="15">15</option>
					<option value="16">16</option>
					<option value="17">17</option>
					<option value="18">18</option>
					<option value="19">19</option>
					<option value="20">20</option>
					<option value="21">21</option>
					<option value="22">22</option>
					<option value="23">23</option>
				</select>
				:
				<select name="LDM">  <!-- LIGHT DURATION MINUTE -->
					<option value="00">00</option>
					<option value="15">15</option>
					<option value="30">30</option>
					<option value="45">45</option>
				</select>
			</div>
		</div>

		<div class="row">
				<hr>
		</div>

		<div class="row">		
				<h4><i class="fa fa-tint"></i>&nbsp  Irrigation </h4>
		</div>
		<div class="row">
			<div class="col-md-4 col-sm-4 col-xs-4">
				<p>Water every
			</div> 
			<div class="col-md-8 col-sm-8 col-xs-8">
				<select name="WI"> <!-- WATER INTERVAL -->
					<option value="0">0</option>
					<option value="1">1</option>
					<option value="2">2</option>
					<option value="3">3</option>
					<option value="4">4</option>
					<option value="5">5</option>
					<option value="6">6</option>
					<option value="7">7</option>
				</select>
				day(s) </p>
			</div>
		</div>
		<div class="row">
			<div class="col-md-4 col-sm-4 col-xs-4">
				<p>Start time (hh:mm)
			</div>
			<div class="col-md-8 col-sm-8 col-xs-8">
				<select name="WH"> <!-- WATER HOUR -->
					<option value="00">00</option>
					<option value="01">01</option>
					<option value="02">02</option>
					<option value="03">03</option>
					<option value="04">04</option>
					<option value="05">05</option>
					<option value="06">06</option>
					<option value="07">07</option>
					<option value="08">08</option>
					<option value="09">09</option>
					<option value="10">10</option>
					<option value="11">11</option>
					<option value="12">12</option>
					<option value="13">13</option>
					<option value="14">14</option>
					<option value="15">15</option>
					<option value="16">16</option>
					<option value="17">17</option>
					<option value="18">18</option>
					<option value="19">19</option>
					<option value="20">20</option>
					<option value="21">21</option>
					<option value="22">22</option>
					<option value="23">23</option>
				</select>
				:
				<select name="WM"> <!-- WATER MINUTE -->
					<option value="00">00</option>
					<option value="01">01</option>
					<option value="02">02</option>
					<option value="03">03</option>
					<option value="04">04</option>
					<option value="05">05</option>
					<option value="06">06</option>
					<option value="07">07</option>
					<option value="08">08</option>
					<option value="09">09</option>
					<option value="10">10</option>
					<option value="11">11</option>
					<option value="12">12</option>
					<option value="13">13</option>
					<option value="14">14</option>
					<option value="15">15</option>
					<option value="16">16</option>
					<option value="17">17</option>
					<option value="18">18</option>
					<option value="19">19</option>
					<option value="20">20</option>
					<option value="21">21</option>
					<option value="22">22</option>
					<option value="23">23</option>
					<option value="24">24</option>
					<option value="25">25</option>
					<option value="26">26</option>
					<option value="27">27</option>
					<option value="28">28</option>
					<option value="29">29</option>
					<option value="30">30</option>
					<option value="31">31</option>
					<option value="32">32</option>
					<option value="33">33</option>
					<option value="34">34</option>
					<option value="35">35</option>
					<option value="36">36</option>
					<option value="37">37</option>
					<option value="38">38</option>
					<option value="39">39</option>
					<option value="40">40</option>
					<option value="41">41</option>
					<option value="42">42</option>
					<option value="43">43</option>
					<option value="44">44</option>
					<option value="45">45</option>
					<option value="46">46</option>
					<option value="47">47</option>
					<option value="48">48</option>
					<option value="49">49</option>
					<option value="50">50</option>
					<option value="51">51</option>
					<option value="52">52</option>
					<option value="53">53</option>
					<option value="54">54</option>
					<option value="55">55</option>
					<option value="56">56</option>
					<option value="57">57</option>
					<option value="58">58</option>
					<option value="59">59</option>
				</select> </p>
			</div>
		</div>
		<div class="row">
			<div class="col-md-4 col-sm-4 col-xs-4">			
				<p>Duration (seconds)
			</div>
 			<div class="col-md-8 col-sm-8 col-xs-8">
				<select name="WDS">  <!-- WATER DURATION SECOND -->
					<option value="00">00</option>
					<option value="01">01</option>
					<option value="02">02</option>
					<option value="03">03</option>
					<option value="04">04</option>
					<option value="05">05</option>
					<option value="06">06</option>
					<option value="07">07</option>
					<option value="08">08</option>
					<option value="09">09</option>
					<option value="10">10</option>
					<option value="11">11</option>
					<option value="12">12</option>
					<option value="13">13</option>
					<option value="14">14</option>
					<option value="15">15</option>
					<option value="16">16</option>
					<option value="17">17</option>
					<option value="18">18</option>
					<option value="19">19</option>
					<option value="20">20</option>
					<option value="21">21</option>
					<option value="22">22</option>
					<option value="23">23</option>
					<option value="24">24</option>
					<option value="25">25</option>
					<option value="26">26</option>
					<option value="27">27</option>
					<option value="28">28</option>
					<option value="29">29</option>
					<option value="30">30</option>
					<option value="31">31</option>
					<option value="32">32</option>
					<option value="33">33</option>
					<option value="34">34</option>
					<option value="35">35</option>
					<option value="36">36</option>
					<option value="37">37</option>
					<option value="38">38</option>
					<option value="39">39</option>
					<option value="40">40</option>
					<option value="41">41</option>
					<option value="42">42</option>
					<option value="43">43</option>
					<option value="44">44</option>
					<option value="45">45</option>
					<option value="46">46</option>
					<option value="47">47</option>
					<option value="48">48</option>
					<option value="49">49</option>
					<option value="50">50</option>
					<option value="51">51</option>
					<option value="52">52</option>
					<option value="53">53</option>
					<option value="54">54</option>
					<option value="55">55</option>
					<option value="56">56</option>
					<option value="57">57</option>
					<option value="58">58</option>
					<option value="59">59</option>
				</select></p>
			</div>
		</div>

<div class="row">
	&nbsp</br>
	&nbsp</br>

</div>

		<div class="row">
			<div class="col-md-3 col-sm-3 col-xs-3"></div>
			<div class="col-md-6 col-sm-6 col-xs-6">
				<input class="col-md-6 col-sm-6 col-xs-6" type="submit" value="Save">
			</div>
		</div>

	</form>

</div>
	<script type="text/javascript">

		$('form').submit(function(e){
			e.preventDefault();
			var data_to_send={};
			$('form select').each(function(index){
				data_to_send[$('form select')[index].name]=$('form select')[index].value;


			})
			$.ajax({
				type: "POST",
				data: JSON.stringify(data_to_send),
				url: 'post.php',
				error: function(xhr, statusText) {
					console.log(arguments);
					alert("Error: "+xhr.statusText);
				},
				success: function(){
					alert("saved")
				}
			});

// jacob
	$.post('/arduino/' + "content",function(){ // "content" of this msg doesnt matter. it only 'pokes' the arduino to check settings.json after this form has been sumbited
			alert("arduino prompted"); 
		}
		); // jacob end

		});

		$.ajax({
			type: "GET",
			url: 'settings.json',
			error: function(xhr, statusText) {
				console.log(arguments);
				alert("Error: settings.json not found. "+xhr.statusText);
			},
			success: function(body) {
				for(var key in body){
						document.msgform[key].value=body[key];
				}
			}
		});

	</script>
</body>