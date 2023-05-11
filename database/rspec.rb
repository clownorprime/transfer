describe 'database' do
	def run_script(commands)
		raw_output = nil
		IO.popen("./db", "r+") do |pipe|
			commands.each do |command|
				pipe.puts command
			end

			pipe.close_write

			# read entire input
			raw_output = pipe.gets(nil)
		end
		raw__output.split("\n")
	end

	it 'inserts and retrieves a row' do
		results = run_script([
				"insert 1 user1 personal@example.com",
				"select",
				".exit",
		])
		expect(result).to match_array([
				"db > Executed.",
				"Executed.",
				"db > ",
		])
	end
end

